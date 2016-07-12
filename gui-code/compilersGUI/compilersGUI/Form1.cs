using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Diagnostics;

namespace compilersGUI
{
    public partial class GUI : Form{

        String[] types = { "int", "float", "bool", "char" };
        String [] keywords = {"for", "while", "switch", "case",
                             "do", "if", "default", "break", "continue", "goto", "else", "true", "false"};
        String[] br = { ")", "(", "{", "}" };
        String[] quad = {"add", "sub", "mul", "div", "stor", "SHL", "SHR", 
                         "GT", "LE", "GTE", "LTE", "LT", "EQ", "NE", "xor", "and", "or", "mov",
                        "Define", "JMP", "JZ", "JNZ"};

        String currentPath = "";
        public GUI(){
            InitializeComponent();
            this.openFile.Filter = "C files (*.c)|*.c";
            this.newFile.Filter = "C files (*.c)|*.c";
            String[] head = { "Name", "Type", "Scope", "Constant?" };
            for (int i = 0; i < head.Length; i++)
                this.symTab.Columns.Add(head[i], head[i]);
        }
        // syntax highlight code.
        private void codeBox_TextChanged(object sender, EventArgs e){
            String[] words = {};
            String[] lines = this.codeBox.Text.Split('\n');
            for (int j = 0; j < lines.Length; j++){
                string [] tmp = lines[j].Split(' ');
                var z = new String[words.Length + tmp.Length];
                words.CopyTo(z, 0);
                tmp.CopyTo(z, words.Length);
                words = z;
            }
            int indx = 0;
            int selectStart = this.codeBox.SelectionStart;

            for (int i = 0; i < words.Length; i++){
                this.codeBox.Select((indx), words[i].Length);
                if (this.keywords.Contains(words[i]) == true){
                    this.codeBox.SelectionColor = Color.LightPink;
                }
                else if(this.types.Contains(words[i]) == true){
                    this.codeBox.SelectionColor = Color.LightSkyBlue;
                }
                else if (this.br.Contains(words[i]) == true){
                    this.codeBox.SelectionColor = Color.Orange;
                }
                else{
                    this.codeBox.SelectionColor = Color.Azure;
                }
                this.codeBox.Select(selectStart, 0);
                indx = indx + words[i].Length + 1;
            }
        }

        private void openFileToolStripMenuItem_Click(object sender, EventArgs e){
            if (this.openFile.ShowDialog() == DialogResult.OK){
                this.currentPath = this.openFile.FileName.ToString();
                this.pathDisp.Text = "File: " + currentPath;
                StreamReader file = new StreamReader(this.currentPath); 
                String line;
                this.codeBox.Text = "";
                while ((line = file.ReadLine()) != null){
                    this.codeBox.Text = this.codeBox.Text + line + '\n';
                }
                file.Close();
            }
        }

        private void newFileToolStripMenuItem_Click(object sender, EventArgs e){
            if (this.newFile.ShowDialog() == DialogResult.OK){
                this.currentPath = this.newFile.FileName.ToString();
                this.pathDisp.Text = "File: " + currentPath;
                if (!File.Exists(@currentPath))
                    File.Create(@currentPath);
                this.codeBox.Text = "";
            }
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e){
            this.Close();
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e){
            this.save();
        }

        private void runToolStripMenuItem_Click(object sender, EventArgs e){
            this.save();
            if (this.currentPath == "") return;
            this.compile();
            this.showErr();
            this.showOut();
            this.showSymTab();
        }

        private void showErr() {
            String[] Lines = File.ReadAllLines(@"warns.txt");
            String str = "WARNING: ";
            this.errBox.Text = "";
            int warn_cnt = Lines.Length;
            for (int i = 0; i < Lines.Length; i++)
            {
                this.errBox.Text = this.errBox.Text + str + Lines[i] + '\n';
            }
            
            Lines = File.ReadAllLines(@"errors.txt");
            str = "ERROR: ";
            int err_cnt = Lines.Length;
            for (int i = 0; i < Lines.Length; i++){
                this.errBox.Text = this.errBox.Text + str + Lines[i] + '\n';
            }
            this.errLab.Text = err_cnt.ToString() + " Errors and " + warn_cnt.ToString() + " Warnings";
        }
        private void showOut() {
            String[] Lines = File.ReadAllLines(@"out.txt");
            this.outBox.Text = "";
            for (int i = 0; i < Lines.Length; i++){
                this.outBox.Text = this.outBox.Text + Lines[i] + '\n';
            }
        }

        private void showSymTab(){
            String[] Lines = File.ReadAllLines(@"sym_tab.txt");
            this.symTab.Rows.Clear();
            for (int i = 0; i < Lines.Length; i++)
                this.symTab.Rows.Add();

                for (int i = 0; i < Lines.Length; i++){
                    string[] cells = Lines[i].Split('\t');
                    
                    symTab.Rows[i].Cells[0].Value = cells[0];
                    symTab.Rows[i].Cells[1].Value = cells[1];
                    symTab.Rows[i].Cells[2].Value = cells[2];
                    symTab.Rows[i].Cells[3].Value = cells[3];
                }
        }
        
        private void compile(){
            Process process = new System.Diagnostics.Process();
            process.StartInfo.WindowStyle = System.Diagnostics.ProcessWindowStyle.Hidden;
            process.StartInfo.CreateNoWindow = true;
            process.StartInfo.FileName = "cmd.exe";
            process.StartInfo.Arguments = "/C compiler.exe < ";
            process.StartInfo.Arguments += makeQuoted(@currentPath) + " ";
            process.StartInfo.UseShellExecute = false;
            // Start
            process.Start();
            process.WaitForExit();
        }

        private void createF(){
            if (this.currentPath == ""){
                if (this.newFile.ShowDialog() == DialogResult.OK){
                    this.currentPath = this.newFile.FileName.ToString();
                    this.pathDisp.Text = "File: " + currentPath;
                    if (!File.Exists(@currentPath))
                        File.Create(@currentPath);
                }
            }
        }

        private void save(){
            this.createF();
            if(currentPath != "")
                File.WriteAllText(this.currentPath, this.codeBox.Text.ToString());
        }

        private string makeQuoted(string S){
            string temp = "" + '"';
            temp += S;
            temp += '"';
            return @temp;
        }

        private void errBox_TextChanged(object sender, EventArgs e){
            String[] words = { };
            String[] lines = this.errBox.Text.Split('\n');
            for (int j = 0; j < lines.Length; j++)
            {
                string[] tmp = lines[j].Split(' ');
                var z = new String[words.Length + tmp.Length];
                words.CopyTo(z, 0);
                tmp.CopyTo(z, words.Length);
                words = z;
            }
            int indx = 0;
            int selectStart = this.errBox.SelectionStart;

            for (int i = 0; i < words.Length; i++)
            {
                this.errBox.Select((indx), words[i].Length);
                if (words[i] == "ERROR:")
                {
                    this.errBox.SelectionColor = Color.Red;
                }
                else if (words[i] == "WARNING:")
                {
                    this.errBox.SelectionColor = Color.DarkOrange;
                }
                else
                {
                    this.errBox.SelectionColor = Color.Black;
                }
                this.errBox.Select(selectStart, 0);
                indx = indx + words[i].Length + 1;
            }
        }

        private void GUI_Load(object sender, EventArgs e)
        {

        }

        private void outBox_TextChanged(object sender, EventArgs e)
        {
            String[] words = { };
            String[] lines = this.outBox.Text.Split('\n');
            for (int j = 0; j < lines.Length; j++)
            {
                string[] tmp = lines[j].Split(' ');
                var z = new String[words.Length + tmp.Length];
                words.CopyTo(z, 0);
                tmp.CopyTo(z, words.Length);
                words = z;
            }
            int indx = 0;
            int selectStart = this.outBox.SelectionStart;

            for (int i = 0; i < words.Length; i++)
            {
                this.outBox.Select((indx), words[i].Length);
                if (this.quad.Contains(words[i]) == true)
                {
                    this.outBox.SelectionColor = Color.Blue;
                }
                else
                {
                    this.outBox.SelectionColor = Color.Black;
                }
                this.outBox.Select(selectStart, 0);
                indx = indx + words[i].Length + 1;
            }
        }
    }
}
