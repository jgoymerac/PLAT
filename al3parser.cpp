/* Jeff Goymerac


	al3parser.cpp




*/


#include <iomanip>
#include <string>
#include <cctype>

bool is_Program= false;
string cookie;

int main()
{
	eatCookie();
	is_Program=is_Routine();


	if (is_Program==false)
	{
		cout<<"INVALID\n";
	}
	else 
	{
		cout<<"Correct\n";
	}

return 0;
}


void eatCookie()
{
	cin>>cookie;
	return;
}

bool is_Routine()
{
	if(cookie=="routine")
	{
		eatCookie();
		if(is_Identifier();)
		{
			eatCookie();
			if(cookie=="$")
			{
				eatCookie();
				if(is_StateSeq();)
				{
					if(cookie=="endr")
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool is_Identifier();
{
	if(cookie=="is"||"+"||"-"||"*"||"/"||"or"||"and"||"not"||"("||")"||"<"||">"||"="||"$"||"!"||"print"||"if"||"else"||
		"endif"||"while"||"endw"||"routine"||"endr"||"run")
	{
		return false;
	}
	else(if islower(cookie[0])
	{
		for(int i=1;i<cookie.length();i++)
		{
			if(!isalnum(cookie[i]))
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

bool is_StateSeq()
{
	if(is_Statement();)
	{
		eatCookie();
		if(cookie=="!")
		{
			return is_StateSeq();
		}
		return true;
	}
	return false
}


bool is_Statement()
{
	if(is_Identifier();)
	{
		eatCookie();
		if(cookie=="is")
		{
			eatCookie();
			return is_Expression();
		}
	}
	else if(cookie=="run")
	{
		eatCookie;
		return is_Identifier();
	}
	else if(cookie=="if")
	{
		eatCookie();
		return is_IfStatement();

	}
	else if(cookie=="while")
	{
		eatCookie();
		return is_While();
	}
	else if (cookie=="print")
	{
		eatCookie();
		return is_Identifier(); 
	}
	return false;
}


bool is_IfStatement()
{
	if (is_Expression();)
	{
		eatCookie();
		if(cookie=="$")
		{
			eatCookie();
			if(is_StateSeq();)
			{
				eatCookie();
				if (cookie=="else")
				{
					eatCookie();
					if(is_StateSeq();)
					{
						eatCookie();
						if(cookie=="endif")
						{
							return true;
						}
					}
				}
				else if(cookie=="endif")
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool is_While()
{
	if(is_Expression();)
	{
		eatCookie();
		if(cookie=="$")
		{
			eatCookie();
			if(is_StateSeq();)
			{
				eatCookie();
				if(cookie=="endw")
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool is_Expression()
{
	if(is_SimpleExpr();)
	{
		eatCookie();
		if(cookie=="<"||">"||"=")
		{
			return is_SimpleExpr();
		}
		return true;
	}
	return false;
}

bool is_SimpleExpr()
{
	if(is_Term();)
	{
		eatCookie();					///need recursive call here
		if (cookie=="+"||"-"||"or")
		{
			eatCookie();
			return is_Term();
		}
		return true;
	}
	return false;
}

bool is_Term()
{
	if(is_Factor();)
	{
		eatcookie();					//Need recursive call here
		if (cookie=="*"||"/"||"and")
		{
			eatCookie();
			return is_Factor();
		}

		return true;
	}
	return false;
}


bool is_Factor()
{
	if(cookie="(")
	{
		eatCookie();
		if(is_Expression();)
		{
			eatCookie();
			if (cookie==")")
			{
				return true;
			}
		}
	}
	else if(cookie=="not")
	{
		eatCookie();
		return is_Factor();
	}
	else if(cookie[0]=="\"")
	{
		
		if(cookie.length()>2 && cookie[cookie.length()-1] =="\"")
		{
			return true;
		}

	}	
	else if(islower(cookie[0]))
	{
		return is_Identifier();
	}	
	else if (isdigit(cookie[0]))
	{
		return is_Number();
	}
return false;
}


bool is_Number()
{
	char c;
	for (int i = 0; i < t; i++)
	{
		state = 1;
		//cin >> s;
		j = 0;
		c = cookie[j];
		

		while (c != NULL)
		{
			
			switch (state)
			{
			case 1 :
				if (c == '+' || c == '-')
				{
					state = 2;
				}
				else if (isdigit(c))
				{
					state = 3;
				}
				else
				{
					state = -1;
				}
				break;


			case 2:
				if (isdigit(c))
				{
					state = 3;
				}
				else
				{
					state = -1;
				}
				break;

			case 3:
				if (isdigit(c))
				{
					state = 3;
				}
				else if (c == '.')
				{
					state = 4;
				}
				else
				{
					state = -1;
				}
				break;

			case 4:
				if (isdigit(c))
				{
					state = 5;
				}
				else
				{
					state = -1;
				}
				break;

			case 5:
				if (isdigit(c))
				{
					state = 5;
				}
				else if (c == 'E' || c == 'e')
				{
					state = 6;
				}
				else
				{
					state = -1;
				}
				break;

			case 6:
				if (isdigit(c))
				{
					if (c == '0')
					{
						state = 9;
					}
					else
					{
						state = 8;
					}
				}
				else if (c == '+' || c == '-')
				{
					state = 7;
				}
				else
				{
					state = -1;
				}
				break;

			case 7:
				if (isdigit(c))
				{
					if (c == '0')
					{
						state = 9;
					}
					else
					{
						state = 8;
					}
				}
				else
				{
					state = -1;
				}
				break;

			case 8:
				if (isdigit(c))
				{
					state = 8;
				}
				else
				{
					state = -1;
				}
				break;

			case 9:
				if (isdigit(c))
				{
					if (c == '0')
					{
						state = 9;
					}
					else
					{
						state = 8;
					}
				}
				else
				{
					state = -1;
				}
				break;
			default :
				break;
			}//switch
			j++;
			c = s[j];
		}//while
	
		if (state == 3)
		{
			return true;
		}
		else if (state == 5)
		{
			return true;
		}
		else if (state == 8)
		{
			return false;
		}
		else
		{
			return false;
		}





	}//for




	return 0;
}
}




