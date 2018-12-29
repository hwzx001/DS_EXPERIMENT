#include"utility.h"

string ReadString() //��ȡ�ַ���
{
	cout << "������һ�����ʽ��\n";
	string str;
	cin >> str;
	return str;
}

int getPriority(string opt) //�����������з��� 
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

vector<string> PreParse(string inputstring) //���ַ�������Ԥ����
{
	vector<string> result;
	int len = inputstring.size();
	string spare_str;
	for (int i = 0;i < len;i++) // ȥ������Ŀո�
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
			|| spare_str[j] == '(' || spare_str[j] == ')' || spare_str[j] == '#')//����ǲ�������ֱ����ӵ�������
		{
			str = spare_str[j];
			result.push_back(str);
			str = "";
		}
		else // ���������
		{
			str = spare_str[j];
			number_str += str;
			str = "";
			if (!isdigit(spare_str[j + 1]))//�����һλ�������֣�˵��������Ѿ���ȡ���
			{
				if (spare_str[j + 1] != '.')//��ΪС����Ҳ���������ַ������Ի���Ҫ����С��
				{
					result.push_back(number_str);
					number_str = "";
				}

			}

		}

	}
	vector<string> last_result;
	int res_num = result.size();
	for (int i = 0;i < res_num;i++) //�Ը�������Ž������֣�����Ǹ��ţ��������һλ�����ַ��ϲ��������浽�µ�������
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


float to_float(string s)//���ַ�������ת��Ϊdouble��������
{
	if (s[0] != '-')//�Ǹ���
	{
		int i = 0, n = 0;
		int point_index = s.find('.');
		float result = 0, under_0 = 0;//under_0�洢С������  
		if (count(s.begin(), s.end(), '.') > 1)
		{
			return 0;//�ַ�����ֻ����1����0��С���㣬��Ȼ�����˳�  
		}
		if (s.find('.') != -1)//�ַ�������С����  
		{
			if ((point_index == 0) || (point_index == s.size() - 1))//С����λ�ú����������ַ�����1λ,�Ҳ��������һλ  
			{
				return 0;
			}
			for (i = 0; i <= point_index - 1; i++)//������������  
			{
				if (s[i] >= '0'&&s[i] <= '9')
				{
					result = result * 10 + s[i] - 48;
				}
			}
			for (i = s.size() - 1; i >= point_index - 1; i--)//����С������  
			{
				if (s[i] >= '0'&&s[i] <= '9')
				{
					if (i == point_index - 1)
					{
						under_0 = under_0 * 0.1 + 0;//i=С����ǰһλ��under_0+0  
					}
					else
					{
						under_0 = under_0 * 0.1 + s[i] - 48;
					}
				}
			}
			result = result + under_0;//���������ֺ�С���������  
		}
		else//�ַ���ֻ����������  
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
	else//�Ǹ���
	{
		string str = s.substr(1, s.length() - 1);
		return to_float(str)*(-1);
	}
}


void inner_cal(stack<double>&opdStack, string opt) //�ԼӼ��˳���#��������
{
	if (opt == "+")
	{
		double rOpd = opdStack.top();//�������
		opdStack.pop();
		double lOpd = opdStack.top();//�Ҳ�����
		opdStack.pop();
		double result = lOpd + rOpd;
		opdStack.push(result);

		cout << "������:" << opt << " " << "������:" << lOpd << " " << rOpd << endl;
	}
	else if (opt == "-")
	{
		double rOpd = opdStack.top();
		opdStack.pop();
		double lOpd = opdStack.top();
		opdStack.pop();
		double result = lOpd - rOpd;
		opdStack.push(result);
		cout << "������:" << opt << " " << "������:" << lOpd << " " << rOpd << endl;
	}
	else if (opt == "*")
	{
		double rOpd = opdStack.top();
		opdStack.pop();
		double lOpd = opdStack.top();
		opdStack.pop();
		double result = lOpd * rOpd;
		opdStack.push(result);
		cout << "������:" << opt << " " << "������:" << lOpd << " " << rOpd << endl;
	}
	else if (opt == "/")
	{
		double rOpd = opdStack.top();
		opdStack.pop();
		double lOpd = opdStack.top();
		opdStack.pop();
		double result = lOpd / rOpd;
		opdStack.push(result);
		cout << "������:" << opt << " " << "������:" << lOpd << " " << rOpd << endl;
	}
	else if (opt == "#")
	{
		double result = opdStack.top();
		opdStack.pop();
		cout << "���Ϊ��" << result << endl;
	}
}

void calculate(vector<string>cal_vector) //�������е�ÿ��Ԫ�ؽ��в��� 
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

void introduction() //�û�˵����
{
	cout << "                      ��׺���ʽ                          \n";
	cout << "��һ���ַ�������ʽ���룬�ɺ��мӡ������ˡ������������������( )\n";
	cout << "�ԡ�#����Ϊ���������(����ʡ�ԣ���\n";
	cout << "����Ҫ�������㣬������y/Y,�����˳�����������n/N \n";
}
bool is_valid(string inputstr)//�ж��ַ����Ƿ�Ϸ�
{
	bool flag = true;
	int len = inputstr.size();
	if (inputstr[len - 1] != '#')
	{
		cout << "ĩβû����ֹ��" << endl;
		flag = false;
	}
	else if (count(inputstr.begin(), inputstr.end(), '#') >= 2)
	{
		cout << "��ֹ������" << endl;
		flag = false;



	}
	else if (count(inputstr.begin(), inputstr.end(), '(') != count(inputstr.begin(), inputstr.end(), ')'))
	{
		cout << "���Ų�ƥ��" << endl;
		flag = false;
	}
	else if (inputstr.find("++") != -1 || inputstr.find("+*") != -1 || inputstr.find("+/") != -1 ||
		inputstr.find("+)") != -1 || inputstr.find("-+") != -1 || inputstr.find("-*") != -1 ||
		inputstr.find("-/") != -1 || inputstr.find("-)") != -1 || inputstr.find("*+") != -1 ||
		inputstr.find("*/") != -1 || inputstr.find("*)") != -1 || inputstr.find("/*") != -1 ||
		inputstr.find("//") != -1 || inputstr.find("/+") != -1 || inputstr.find("/-") != -1 ||
		inputstr.find("(/") != -1 || inputstr.find("/)") != -1)
	{
		cout << "�������ƥ��";
		flag = false;
	}
	else if (inputstr[0]=='+'||inputstr[0]=='*'||inputstr[0]=='/')
	{
		cout << "�����һ���ַ�Ϊ�����";
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
				cout << "���зǷ��ַ�";
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
		  cout << "��������ȷ�ı��ʽ";
		  goto Loop;
	  }
	}

	  system("pause");

}

