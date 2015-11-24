///////////////////////////////////////////
///	@file Lex.cpp						///		
/// @author Jeff Goymerac CS 3500		///
/// @brief Lexical analyzer				///
///////////////////////////////////////////
#include <iostream>
//#include <iomanip>
#include <string>
//#include <stdlib.h>

using namespace std;


int main()
{
	char c;
	int j, t, state;
	string s;
	
	cin >> t;
	cout << t <<"\n";

	for (int i = 0; i < t; i++)
	{
		state = 1;
		cin >> s;
		j = 0;
		c = s[j];
		

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
			cout << "Found an Integer. \n";

		}
		else if (state == 5)
		{
			cout << "Found a Decimal. \n";
		}
		else if (state == 8)
		{
			cout << "Found a Scientific. \n";
		}
		else
		{
			cout << "Invalid! \n";
		}





	}//for




	return 0;
}