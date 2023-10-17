#include<iostream>
#include<string.h>
#include<vector>
#include<utility>
#include<cstdlib>
using namespace std;
class AccountDetails
{
    int balance=0,deposit=0,withdraw=0;
    int dodgecoin=0,bitcoin=0,litecoin=0;
    int dodgecoin_value=3500;
    int bitcoin_value=10000;
    int litecoin_value=7600;
    int crypto_invest=0,crypto_return=0;
    int equity=1000;
    vector<pair<string,int>> transactions; 
    public:
    string name;
    void Deposit(int amount)
    {
        deposit=deposit+amount;
        balance=balance+amount;
        transactions.push_back({"Deposited:",amount});
        cout<<"The money has been successfully deposited"<<endl;
    }
    bool Withdraw(int amount)
    {
        if(amount>=balance)
        {
            cout<<"Not enough balance!";
            return false;
        }
        else
        {
            balance=balance-amount;
            transactions.push_back({"Withdrawed:",amount});
            cout<<"The money has been successfully withdrawed"<<endl;
            return true;
        }
    }    
    void Account_Info()
    {
        cout<<"Details:-"<<endl;
        cout<<"Name:"<<name<<endl;
        cout<<"Balance:"<<balance<<endl;
        cout<<"Bitcoin:"<<bitcoin<<endl;
        cout<<"Litecoin:"<<litecoin<<endl;
        cout<<"Dodgecoin:"<<dodgecoin<<endl;
    }
    bool Buy_Crypto()
    {
       int choice1;
       cout<<"List of crypto currencies available:-"<<endl;
       cout<<"1.Bitcoin"<<endl;
       cout<<"2.Dodgecoin"<<endl;
       cout<<"3.Litecoin"<<endl;
       cout<<"Enter your choice:";
       cin>>choice1;
       if(equity!=0)
       {
          
          if(choice1==1)
          {
            if(balance>bitcoin_value)
            {
                ++bitcoin;
                balance=balance-bitcoin_value;
                crypto_invest=crypto_invest+bitcoin_value; 
                transactions.push_back({"Bitcoin bought for:",bitcoin_value});
                cout<<"Successfully bought a bitcoin"<<endl;
            }
            else
            {
                cout<<"Not enough balance!"<<endl;
            }
           
          }
          else if(choice1==2)
          {
            if(balance>dodgecoin_value)
            {
                ++dodgecoin;
                balance=balance-dodgecoin_value;
                crypto_invest=crypto_invest+dodgecoin_value;
                transactions.push_back({"Dodgecoin bought for:",dodgecoin_value});
                cout<<"Successfully bought a dodgecoin"<<endl;
            }
            else
            {
              cout<<"Not enough balance!"<<endl;   
            }
          }
          else if(choice1==3)
          {
            if(balance>litecoin_value)
            {
                ++litecoin;
                balance=balance-litecoin_value;
                crypto_invest=crypto_invest+litecoin_value;
                transactions.push_back({"Litecoin bought for:",litecoin_value});
                cout<<"Successfully bought a litecoin"<<endl;
            }
            else
            {
              cout<<"Not enough balance!"<<endl;   
            }
          }
          else
          {
            cout<<"Wrong choice!"<<endl;
          }
        }
        else
        {
        return false;
        }
        return true;
    }
    bool Sell_Crypto()
    {
       int choice2;
       cout<<"List of crypto currencies available:-"<<endl;
       cout<<"1.Bitcoin"<<endl;
       cout<<"2.Dodgecoin"<<endl;
       cout<<"3.Litecoin"<<endl;
       cout<<"Enter your choice:";
       cin>>choice2;
       if(choice2==1)
       {
        if(bitcoin!=0)
        {
            crypto_return=crypto_return+bitcoin_value;
            balance=balance+bitcoin_value;
            transactions.push_back({"Bitcoin sold for:",bitcoin_value});
            bitcoin--;
            cout<<"Succesfully sold a bitcoin"<<endl;
        }
        else
        {
            cout<<"No bitcoins available"<<endl;
            return false;
        }
       } 
       else if(choice2==2)
       {
           if(dodgecoin!=0)
            {
            crypto_return=crypto_return+dodgecoin_value;
            balance=balance+dodgecoin_value;
            transactions.push_back({"dodgecoin sold for:",dodgecoin_value});
            dodgecoin--;
            cout<<"Succesfully sold a dodgecoin"<<endl;
            }
            else
            {
              cout<<"No dodgecoins available"<<endl;  
              return false;
            }
       }
        else if(choice2==3)
       {
            if(litecoin!=0)
            {
            crypto_return=crypto_return+litecoin_value;
            balance=balance+litecoin_value;
            transactions.push_back({"Litecoin sold for:",litecoin_value});
            litecoin--;
            cout<<"Succesfully sold a litecoin"<<endl;
            }
            else
            {
              cout<<"No litecoins available"<<endl;
              return false;
            }   
        }
        else
        {
            cout<<"Wrong choice!"<<endl;
            return false;
        }
        return true;
    } 
    void Transaction_History()
    {
        cout<<"Transactions:-"<<endl;
        for(int i =0;i<transactions.size();i++)
        {
        cout<<transactions[i].first<<transactions[i].second<<"\n";
        }
        int option;
        cout<<"Do you want to clear all transactions?"<<endl;
        cout<<"If YES enter 1:";
        cin>>option;
        if(option==1)
        {
            transactions.clear();
            cout<<"Your transactions have been succesfully cleared"<<endl;
        }
        cout<<"Total number of transactions:"<<transactions.size()<<endl;
    }       
};
int main()
{
AccountDetails p1;
cout<<"Enter your name:";
cin>>p1.name;
int choice,cash;
int i=1;
while(i)
{
cout<<"1.To deposit"<<endl;
cout<<"2.To witdraw"<<endl;
cout<<"3.Display account details"<<endl;
cout<<"4.To buy crypto"<<endl;
cout<<"5.To sell crypto"<<endl;
cout<<"6.To view transactions"<<endl;
cout<<"To exit enter a number other that 1-6"<<endl;
cout<<"Enter your choice:";
cin>>choice;
switch(choice)
{
    case 1:cout<<"Enter amount to be deposited:";
           cin>>cash;
           p1.Deposit(cash);
           break;
    case 2:cout<<"Enter amount to be withdraw:";
           cin>>cash;
           p1.Withdraw(cash);
           break;
    case 3:p1.Account_Info();
           break;   
    case 4:p1.Buy_Crypto();
           break; 
    case 5:p1.Sell_Crypto();
           break;
    case 6:p1.Transaction_History();
           break;
    default:exit(0);
            break;                                
}
}
}