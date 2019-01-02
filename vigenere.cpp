#include <iostream>
using namespace std;
int count(string pass);
string encrypt(int i, string pass, int c_key[]);
void output(int i, string c_pass);
int main() {
  string password;
  string key;
  cout << "請輸入明文:";
  cin >> password;
  cout << "請輸入密鑰:";
  cin >> key;
  int i = count(password);
  int j = count(key);
  int c_key[40] = {0};
  int k = 0;
  while(k < i)
    {
      for(int m = 0; m < j; m++)
        {
          c_key[k] = (int)key[m] - 'a';
          k++;
        }
    }
  output(i, encrypt(i, password, c_key)); 
}
//計算密碼位數
int count(string pass)
  {
    int i=0;
    while((int)pass[i] != 0)
      {
        i++;
      }
    return i;
  }
//密碼加密
string encrypt(int i, string pass, int c_key[])
  {
    string c_pass;
    for(int j = 0; j < i; j++)
    {
      if((int)pass[j] <= 'z' && (int)pass[j] >= 'a')
        {
          c_pass[j] = ((int)pass[j] + c_key[j] - 'a') % 26 + 'a';
        }
      else if((int)pass[j] <= 'Z' && (int)pass[j] >= 'A')
        {
          c_pass[j] = ((int)pass[j] + c_key[j] - 'A') % 26 + 'A';
        }
      else
        {
          c_pass[j] = pass[j];
        }        
    }
    return c_pass;    
  }
//輸出加密後的字串
void output(int i, string c_pass)
  {
    cout << "密文：";
    for (int k=0; k < i; k++)
    {
      cout << c_pass[k];
    }
  }
