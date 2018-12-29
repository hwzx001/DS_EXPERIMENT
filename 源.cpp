#include"utility.h"

string ReadString() //读取字符串
{
	cout << "请输入一个表达式：\n";
	string str;
	cin >> str;
	return str;
}

int getPriority(string opt) //将操作符进行分类 
{
	int priority;
	if (opt == "#")
		priority = 3;
	else if (opt == "*" || opt == "/")
		priority = 2;
	else if (opt == "+" || opt == "-")
		priority = 1;
	else if (opt == "(")
		priority = 0;
	return priority;
}

vector<string> PreParse(string inputstring) //对字符串进行预处理
{
	vector<string> result;
	int len = inputstring.size();
	string spare_str;
	for (int i = 0;i < len;i++) // 去除多余的空格
	{

		if (inputstring[i] != ' ')
		{
			spare_str.push_back(inputstring[i]);
		}
	}
	int spare_len = spare_str.size();
	string number_str = "";
	string str = "";
	for (int j = 0;j < spare_len;j++)
	{
		if (spare_str[j] == '+' || spare_str[j] == '-' || spare_str[j] == '*' || spare_str[j] == '/'
			|| spare_str[j] == '(' || spare_str[j] == ')' || spare_str[j] == '#')//如果是操作符，直接添加到向量中
		{
			str = spare_str[j];
			result.push_back(str);
			str = "";
		}
		else // 如果是数字
		{
			str = spare_str[j];
			number_str += str;
			str = "";
			if (!isdigit(spare_str[j + 1]))//如果后一位不是数字，说明这个数已经读取完毕
			{
				if (spare_str[j + 1] != '.')//因为小数点也不是数字字符，所以还需要考虑小数
				{
					result.push_back(number_str);
					number_str = "";
				}

			}

		}

	}
	vector<string> last_result;
	int res_num = result.size();
	for (int i = 0;i < res_num;i++) //对负号与减号进行区分，如果是负号，则与后面一位数字字符合并，并保存到新的向量中
	{
		if (result[i] == "-")
		{
			if ((i - 1) >= 0 && (result[i - 1] == ")" || isdigit(result[i - 1][0])))
				last_result.push_back(result[i]);
			else
			{
				string str;
				if (i < res_num - 2)
				{
					str = result[i] + result[i + 1];
					i++;
					last_result.push_back(str);
				}
				else
					break;
			}

		}
		else
			last_result.push_back(result[i]);
	}
	/*while (j < spare_len)
	{
		string str;
		if (spare_str[j] == '+' || spare_str[j] == '-' || spare_str[j] == '*' || spare_str[j] == '/'
			|| spare_str[j] == '(' || spare_str[j] == ')' || spare_str[j] == '#')
		{
			if (isdigit(spare_str[j - 1]) && (j - 1) >= 0)
			{

				result.push_back(number_str);
				number_str = "";
			}
			str = spare_str[j];
			result.push_back(str);

		}
		else
		{
			if (spare_str[j] >= '0'&&spare_str[j] <= '9' || spare_str[j] == '.')
			{
				number_str += spare_str[j];
			}

		}
		j++;
	}*/
	return last_result;
}


float to_float(string s)//将字符串数字转化为double类型数字
{
	if (s[0] != '-')//非负数
	{
		int i = 0, n = 0;
		int point_index = s.find('.');
		float result = 0, under_0 = 0;//under_0存储小数部分  
		if (count(s.begin(), s.end(), '.') > 1)
		{
			return 0;//字符串里只能有1个或0个小数点，不然出错退出  
		}
		if (s.find('.') != -1)//字符串里有小数点  
		{
			if ((point_index == 0) || (point_index == s.size() - 1))//小数点位置合理，不能在字符串第1位,且不能在最后一位  
			{
				return 0;
			}
			for (i = 0; i <= point_index - 1; i++)//计算整数部分  
			{
				if (s[i] >= '0'&&s[i] <= '9')
				{
					result = result * 10 + s[i] - 48;
				}
			}
			for (i = s.size() - 1; i >= point_index - 1; i--)//计算小数部分  
			{
				if (s[i] >= '0'&&s[i] <= '9')
				{
					if (i == point_index - 1)
					{
						under_0 = under_0 * 0.1 + 0;//i=小数点前一位，under_0+0  
					}
					else
					{
						under_0 = under_0 * 0.1 + s[i] - 48;
					}
				}
			}
			result = result + under_0;//把整数部分和小数部分相加  
		}
		else//字符串只有整数部分  
		{
			for (i = 0; i <= s.size() - 1;i++)
			{
				if (s[i] >= '0'&&s[i] <= '9')
				{
					result = result * 10 + s[i] - 48;
				}
			}
		}

		return result;
	}
	else//是负数
	{
		string str = s.substr(1, s.length() - 1);
		return to_float(str)*(-1);
	}
}


void inner_cal(stack<double>&opdStack, string opt) //对加减乘除和#进行运算
{
	if (opt == "+")
	{
		double rOpd = opdStack.top();//左操作数
		opdStack.pop();
		double lOpd = opdStack.top();//右操作数
		opdStack.pop();
		double result = lOpd + rOpd;
		opdStack.push(result);

		cout << "操作符:" << opt << " " << "操作数:" << lOpd << " " << rOpd << endl;
	}
	else if (opt == "-")
	{
		double rOpd = opdStack.top();
		opdStack.pop();
		double lOpd = opdStack.top();
		opdStack.pop();
		double result = lOpd - rOpd;
		opdStack.push(result);
		cout << "操作符:" << opt << " " << "操作数:" << lOpd << " " << rOpd << endl;
	}
	else if (opt == "*")
	{
		double rOpd = opdStack.top();
		opdStack.pop();
		double lOpd = opdStack.top();
		opdStack.pop();
		double result = lOpd * rOpd;
		opdStack.push(result);
		cout << "操作符:" << opt << " " << "操作数:" << lOpd << " " << rOpd << endl;
	}
	else if (opt == "/")
	{
		double rOpd = opdStack.top();
		opdStack.pop();
		double lOpd = opdStack.top();
		opdStack.pop();
		double result = lOpd / rOpd;
		opdStack.push(result);
		cout << "操作符:" << opt << " " << "操作数:" << lOpd << " " << rOpd << endl;
	}
	else if (opt == "#")
	{
		double result = opdStack.top();
		opdStack.pop();
		cout << "结果为：" << result << endl;
	}
}

void calculate(vector<string>cal_vector) //对向量中的每个元素进行操作 
{
	stack<double>numbers;
	stack<string>operation;
	string str1;
	int len = cal_vector.size();
	for (int i = 0;i < len;i++)
	{
		str1 = cal_vector[i];
		if (str1 == "+" || str1 == "-" || str1 == "*" || str1 == "/")
		{
			if (operation.empty())
				operation.push(str1);
			else
			{
				int strpriority = getPriority(str1);
				string topopt = operation.top();
				int toppriority = getPriority(topopt);
				if (strpriority > toppriority)
				{
					operation.push(str1);
				}
				else
				{
					while (strpriority <= toppriority)
					{
						operation.pop();
						inner_cal(numbers, topopt);
						if (operation.size() > 0)
						{
							topopt = operation.top();
							toppriority = getPriority(topopt);

						}
						else
							break;
					}
					operation.push(str1);
				}
			}
		}
		else if (str1 == "(")
		{
			operation.push(str1);
		}
		else if (str1 == ")")
		{
			while (operation.top() != "(")
			{
				string topopt = operation.top();
				inner_cal(numbers, topopt);
				operation.pop();

			}
			operation.pop();
		}
		else if (str1 == "#")
		{
			while (operation.size() != 0)
			{
				string opt = operation.top();
				inner_cal(numbers, opt);
				operation.pop();
			}
			inner_cal(numbers, str1);
		}
		else
		{
			double str_num = to_float(str1);
			numbers.push(str_num);
		}
	}
}

void introduction() //用户说明书
{
	cout << "                      中缀表达式                          \n";
	cout << "以一个字符串的形式读入，可含有加、减、乘、除运算符和左、右括号( )\n";
	cout << "以“#”作为输入结束符(不可省略）。\n";
	cout << "若需要继续计算，请输入y/Y,若需退出程序，请输入n/N \n";
}
bool is_valid(string inputstr)//判断字符串是否合法
{
	bool flag = true;
	int len = inputstr.size();
	if (inputstr[len - 1] != '#')
	{
		cout << "末尾没有终止符" << endl;
		flag = false;
	}
	else if (count(inputstr.begin(), inputstr.end(), '#') >= 2)
	{
		cout << "终止符过多" << endl;
		flag = false;



	}
	else if (count(inputstr.begin(), inputstr.end(), '(') != count(inputstr.begin(), inputstr.end(), ')'))
	{
		cout << "括号不匹配" << endl;
		flag = false;
	}
	else if (inputstr.find("++") != -1 || inputstr.find("+*") != -1 || inputstr.find("+/") != -1 ||
		inputstr.find("+)") != -1 || inputstr.find("-+") != -1 || inputstr.find("-*") != -1 ||
		inputstr.find("-/") != -1 || inputstr.find("-)") != -1 || inputstr.find("*+") != -1 ||
		inputstr.find("*/") != -1 || inputstr.find("*)") != -1 || inputstr.find("/*") != -1 ||
		inputstr.find("//") != -1 || inputstr.find("/+") != -1 || inputstr.find("/-") != -1 ||
		inputstr.find("(/") != -1 || inputstr.find("/)") != -1)
	{
		cout << "运算符不匹配";
		flag = false;
	}
	else if (inputstr[0]=='+'||inputstr[0]=='*'||inputstr[0]=='/')
	{
		cout << "输入第一个字符为运算符";
		flag = false;

	}
	else
	{
		for (int i = 0;i < len;i++)
		{
			
			if( !(inputstr[i] == '+' || inputstr[i] == '-' || inputstr[i] == '*' || inputstr[i] == '/'
				|| inputstr[i] == '(' || inputstr[i] == ')' || inputstr[i] == '#' || inputstr[i] == '.'
				|| inputstr[i] == '0' || inputstr[i] == '1' || inputstr[i] == '2' ||
				inputstr[i] == '3' || inputstr[i] == '4' || inputstr[i] == '5 ' || inputstr[i] == ' 6' ||
				inputstr[i] == '7 ' || inputstr[i] == '8 ' || inputstr[i] == '9'
				))
			{
				cout << "含有非法字符";
				flag = false;
				break;
			}

		}
	}
	
		return flag;
}
int main()
{
	introduction();
  Loop: {
	string str = ReadString();
	if (is_valid(str)) {
	    vector<string> cal_vector = PreParse(str);
	    calculate(cal_vector);
		while (user_says_yes())
		{
			goto Loop;
		}
    }
	  else
	  {
		  cout << "请输入正确的表达式";
		  goto Loop;
	  }
	}

	  system("pause");

}

