using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace EnumGen
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		protected override void OnShown(EventArgs e)
		{
			string file = @"C:\Program Files (x86)\NVIDIA Corporation\APEX\1.3.1\module\destructible\public\NxDestructibleAsset.h";
			string structName = "NxDestructibleParametersFlag";

			string code = File.ReadAllText(file);

			string[] lines = code.Split(new[] { Environment.NewLine }, StringSplitOptions.None);

			int start = 0;
			bool readComment = false;
			bool justFinishedReadingComment = false;
			string comment = null;
			string enumVal = null;

			var enums = new List<Tuple<string, string>>();

			foreach (var line in lines)
			{
				if (line.Contains("};") && enums.Any())
					break;

				if (line.Contains("struct " + structName))
					start++;

				if (start == 1 && line.Contains("enum Enum"))
					start++;

				if (start == 2)
				{
					if (line.Contains("/*"))
					{
						justFinishedReadingComment = false;
						readComment = true;
					}
					if (line.Contains("*/"))
					{
						readComment = false;
						justFinishedReadingComment = true;
						continue;
					}

					if (readComment)
					{
						comment += "\n" + line.Trim();
					}

					if (justFinishedReadingComment)
					{
						enumVal = line.Trim();
						var x = enumVal.Split('=');

						string niceEnumVal = System.Threading.Thread.CurrentThread.CurrentCulture.TextInfo
							.ToTitleCase(x[0].ToLower().Trim().Replace("_", " "))
							.Replace(" ", "")
							.Trim();

						string j = niceEnumVal + " = " + structName + "::" + x[0].Trim() + ",";

						comment = comment
							.Trim()
							.Replace("/**", "")
							.Replace("*/", "")
							.Replace("\n", " ")
							.Replace(" Nx", " ")
							.Trim();

						enums.Add(new Tuple<string, string>(j, comment));

						justFinishedReadingComment = false;
						comment = string.Empty;
					}
				}
			}

			string top =
@"#pragma once

namespace PhysX
{
namespace Apex
{
	public enum class " + structName.Substring(2) + @"
	{
";

			string middle = string.Empty;

			foreach (var z in enums)
			{
				string q = z.Item2;
				var commentLines = new List<string>();
				while (true)
				{
					if (q.Length >= 120)
					{
						int split = 120;
						while (q[split - 1] != ' ')
						{
							split--;
						}

						commentLines.Add(q.Substring(0, split));
						q = q.Substring(split);
					}
					else
					{
						commentLines.Add(q);
						break;
					}
				}

				middle += "		/// <summary>\n";
				foreach (var commentLine in commentLines)
				{
					middle += "		/// " + commentLine + "\n";
				}
				middle += "		/// </summary>\n";
				middle += "		" + z.Item1;
				middle += Environment.NewLine;
				middle += Environment.NewLine;
			}

			string bottom = @"	};
};
};";

			uxH.Text = top + middle + bottom;
			Clipboard.SetText(uxH.Text);
		}
	}
}
