#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
fstream pl,plc;
fstream cch,cchc;
fstream dta,dtac;
fstream sdm,sdmc;
fstream tm,tmc;
fstream matchdata;
fstream ump,umpc;
fstream umpd;
fstream ptt;
class team	//Class to store team details
{
	int team_id;
	char team_name[40];
	char team_owner[40];
	char team_captain[40];
	char team_coach[40];
	public:
		void get_datat()
		{
			cout<<endl<<"Enter team ID: ";
			cin>>team_id;
			fflush(stdin);
			cin.ignore();
			cout<<endl<<"Enter team name: ";
			cin.getline(team_name,40);
			cout<<endl<<"Enter the name of team owner: ";
			cin.getline(team_owner,40);
			cout<<endl<<"Enter the name of Team Captain: ";
			cin.getline(team_captain,40);
			cout<<endl<<"Enter the name of Team Coach: ";
			cin.getline(team_coach,40);
		}
		void put_datat()
		{
			cout<<endl<<"Team ID: "<<team_id;
			cout<<endl<<"Team name: "<<team_name;
			cout<<endl<<"Name of team owner: "<<team_owner;
			cout<<endl<<"Name of Team Captain: "<<team_captain;
			cout<<endl<<"Name of Team Coach: "<<team_coach<<endl;
		}
		int return_teamid()
		{
			return team_id;
		}
};
class coach{	//Class to store coach details	
    int coach_id;
    char coach_name[40];
    char coach_team[40];
    int coach_age;
public:
    void get_datac() //Member Function to enter Coach's details
    {
        cout<<endl<<"Enter Coach ID: ";
        cin>>coach_id;
        fflush(stdin);
        cin.ignore();
        cout<<endl<<"Enter Coach's name: ";
        cin.getline(coach_name,40);
        cout<<endl<<"Enter team's name: ";
        cin.getline(coach_team,40);
        fflush(stdin);
        cin.ignore();
        cout<<endl<<"Enter age of the Coach: ";
        cin>>coach_age;
        cout<<endl<<"Data Successfully Entered";
    }
    void putdatac() //Member Function to display Coach's details
    {
        cout<<endl<<"Coach ID: "<<coach_id;
        cout<<endl<<"Coach's Name: "<<coach_name;
        cout<<endl<<"Team: "<<coach_team;
        cout<<endl<<"Age of Coach: "<<coach_age<<endl;
    }
    int return_coachid()
    {
    	return coach_id;
	}
	void showlastid()
	{
		cout<<endl<<"Last Entered ID: "<<coach_id;
	}
};
class player{	//Class to store player details
protected:
    int player_id;
    char player_name[40];
    char player_team[40];
    int player_age;
    char bowling_style[20];
    char batting_style[20];
    //Batting
    int player_innings;
    int player_match;
    int player_highestscore;
    int player_cents;
    int player_halfcents;
    int player_no4s;
    int player_no6s;
    //Bowling
    int player_overs,player_wickets;
    //Fielding
    int player_catches;
    //Other
    string player_retaintion;
public:
    player()
    {
    	player_match=0;
        player_innings=0;
        player_highestscore=0;
        player_cents=0;
        player_halfcents=0;
        player_no4s=0;
        player_no6s=0;
        player_overs=0;
        player_wickets=0;
        player_catches=0;
    }
    int retid()
    {
        return player_id;
    }
    char* return_name()
    {
    	return player_name;
	}
    void get_datap()
    {
        cout<<endl<<"Enter player ID: ";
        cin>>player_id;
        fflush(stdin);
        cin.ignore();
        cout<<endl<<"Enter player's name: ";
        cin.getline(player_name,40);
        cout<<endl<<"Enter player's team: ";
        cin.getline(player_team,40);
        fflush(stdin);
        cin.ignore();
        cout<<endl<<"Enter player's age: ";
        cin>>player_age;
        fflush(stdin);
        cin.ignore();
        cout<<endl<<"Enter player's bowling style: ";
        cin.getline(bowling_style,20);
        cout<<endl<<"Enter player's batting style: ";
        cin.getline(batting_style,20);

    }
    void put_datap() {
        cout << endl << "Player ID: " << player_id;
        cout << endl << "Player's name: " << player_name;
        cout << endl << "Player's team: " << player_team;
        cout << endl << "Player's age: " << player_age;
        cout << endl << "Bowling style: " << bowling_style;
        cout << endl << "Batting style: " << batting_style<<endl;
    }
    void plname()
    {
        cout<<endl<<"Man of the Match: "<<player_name<<endl;
    }
    void idshow()
    {
    	cout<<endl<<"Last ID Entered: "<<player_id;
	}
};
class stadium{	//Class to store stadium details
	protected:
    int stadium_id;
    char stadium_name[40];
    char stadium_city[40];
    char team_stadium[40];
    int capacity;
    public:
    void getdatas()
    {
        cout<<endl<<"Enter stadium ID: ";
        cin>>stadium_id;
        fflush(stdin);
        cin.ignore();
        cout<<endl<<"Enter stadium name:";
        cin.getline(stadium_name,40);
        cout<<endl<<"Enter stadium city: ";
        cin.getline(stadium_city,40);
        cout<<endl<<"Enter teams related to stadium: ";
        cin.getline(team_stadium,40);
        fflush(stdin);
        cin.ignore();
        cout<<endl<<"Enter capacity: ";
        cin>>capacity;
    }
    void putdatas()
    {
        cout<<endl<<"Stadium ID: "<<stadium_id;
        cout<<endl<<"Stadium name:"<<stadium_name;
        cout<<endl<<"Stadium city: "<<stadium_city;
        cout<<endl<<"Team related to stadium: "<<team_stadium;
        cout<<endl<<"Capacity: "<<capacity<<endl;
  	}
  	int return_stadiumid()
  	{
  		return stadium_id;	
 	}
};
class match{	//Class to store match details
    int match_no;
    char teama[40];
    char teamb[40];
    int plrid[22];
    int run[22];
    int wicket[22];
    int totalrun1,totalrun2;
    int manofthematch_index,manofthematchid,manofthematchpoint;
public:
	match()
	{
		totalrun1=0;
		totalrun2=0;
	}
    void getdatam()
    {
        cout<<endl<<"Enter Match No: ";
        cin>>match_no;
        fflush(stdin);
        cin.ignore();
        cout<<"\nEnter the name of Team A: ";
        cin.getline(teama,40);
        cout<<"\nEnter the name of Team B: ";
        cin.getline(teamb,40);
        cout<<endl<<"Record: ";
        for(int i=0;i<22;i++)
        {
        	if(i<=11)
        	{
        	cout<<endl<<"Team 1: ";
            cout<<endl<<i+1<<") "<<"Enter player ID: ";
            cin>>plrid[i];
            cout<<endl<<"Enter runs scored: ";
            cin>>run[i];
            cout<<"Enter the no of wickets taken: ";
            cin>>wicket[i];
            totalrun1+=run[i];
        	}
        	else if(i>11)
        	{
        	cout<<endl<<"Team 2: ";
            cout<<endl<<i+1<<") "<<"Enter player ID: ";
            cin>>plrid[i];
            cout<<endl<<"Enter runs scored: ";
            cin>>run[i];
            cout<<"Enter the no of wickets taken: ";
            cin>>wicket[i];
            totalrun2+=run[i];
        	}
        }
            manofthematchpoint=run[0]+wicket[0];
            for(int i=0;i<22;i++)
            {
            	if(run[i]+wicket[i]>manofthematchpoint)
            	{
            		manofthematchpoint=run[i]+wicket[i];
            		manofthematch_index=i;
				}
			}
			manofthematchid=plrid[manofthematch_index];
    }
    void putdatam()
    {
    	cout<<endl<<"Match No: "<<match_no;
    	cout<<endl<<teama<<" V/S "<<teamb;
    	cout<<endl<<"Man of the Match ID: "<<manofthematchid;
    	cout<<endl<<"Team A Score: "<<totalrun1;
    	cout<<endl<<"Team B Score: "<<totalrun2;
    	if(totalrun1>totalrun2)
        {
        	cout<<endl<<"Winner: "<<teama<<endl;
		}
		else
		{
			cout<<endl<<"Winner: "<<teama<<endl;
		}
	}
	int retmid()
	{
		return manofthematchid;
	}
};
class data : protected player	//Class to store data related to players
{
public:
    void getdatad()
    {   int tempdata;
        cout<<endl<<"Enter Player ID: ";
        cin>>player_id;
        fflush(stdin);
        cin.ignore();
        cout<<endl<<"Enter Player Name: ";
        cin.getline(player_name,40);
        cout<<endl<<"Enter Player Team: ";
        cin.getline(player_team,40);
        fflush(stdin);
        cin.ignore();
        cout<<endl<<"Enter no of matches played: ";
        cin>>tempdata;
        player_match+=tempdata;
        cout<<endl<<"Enter no of Innings played: ";
        cin>>tempdata;
        player_innings+=tempdata;
        cout<<endl<<"Enter score: ";
        cin>>tempdata;
        player_highestscore+=tempdata;
        cout<<endl<<"Enter the count if there's century: ";
        cin>>tempdata;
        player_cents+=tempdata;
        cout<<endl<<"Enter the count if there's half century: ";
        cin>>tempdata;
        player_halfcents+=tempdata;
        cout<<endl<<"Enter no of 4s: ";
        cin>>tempdata;
        player_no4s+=tempdata;
        cout<<endl<<"Enter no of 6s: ";
        cin>>tempdata;
        player_no6s+=tempdata;
        cout<<endl<<"Enter no of overs played: ";
        cin>> tempdata;
        player_overs+= tempdata;
        cout<<endl<<"Enter no of wickets taken: ";
        cin>>tempdata;
        player_wickets+=tempdata;
        cout<<endl<<"No of catches taken: ";
        cin>>tempdata;
        player_catches+=tempdata;

    }
    void put_datad()
    {
    	cout << endl <<"Player ID: "<<player_id;
        cout << endl << "Player's name: " << player_name;
        cout << endl << "Player's team: " << player_team;
        cout<< endl<<"No of matches played: " <<player_match;
        cout << endl << "Batting: ";
        cout << endl << "Innings: " << player_innings;
        cout << endl << "Highest Score: " << player_highestscore;
        cout << endl << "Centuries: " << player_cents;
        cout << endl << "Half Centuries: " << player_halfcents;
        cout << endl << "No of 4s: " << player_no4s;
        cout << endl << "No of 6s: " << player_no6s;
        cout << endl << "Bowling: ";
        cout << endl << "Overs: " << player_overs;
        cout << endl << "Wickets: " << player_wickets;
        cout << endl << "Fielding: ";
        cout << endl << "No of Catches: " << player_catches;
        if(player_highestscore>35||player_wickets>2)
        {
            cout<<endl<<"Retaintion Status: Yes"<<endl;
        }
        else
        {
            cout<<endl<<"Retaintion Status: No"<<endl;
        }
    }
    int retscore()
    {
    	return player_highestscore;
	}
    int retcent()
    {
    	return player_cents;
	}
	int ret6()
	{
		return player_no6s;
	}
    int ret4()
    {
    	return player_no4s;
	}
	int retw()
    {
    	return player_wickets;
	}
    int retiddata()
    {
        return player_id;
    }
    void maxcentplayer()
    {
    	cout<<endl<<"Player with maximum no of centuries: "<<player_name;
	}
    void maxrunplayer()
    {
    	cout<<endl<<"Player with maximum run rate: "<<player_name;
	}
	void maxwicketplayer()
    {
    	cout<<endl<<"Player who had taken maximum wickets: "<<player_name;
	}
	void max6()
    {
    	cout<<endl<<"Player with maximum no of 6s: "<<player_name;
	}
	void max4()
    {
    	cout<<endl<<"Player with maximum no of 4s: "<<player_name;
	}
};
class umpire{	//Class to store umpire details
	protected:
	int umpire_id;
	char umpire_name[40];
	int onfieldcount;
	int correctdecision;
	int wrongdecision;
	public:
	umpire()
	{
		onfieldcount=0;
		correctdecision=0;
		wrongdecision=0;
	}
	void get_datau()
	{
		cout<<endl<<"Enter Umpire ID: ";
		cin>>umpire_id;
		fflush(stdin);
		cin.ignore();
		cout<<endl<<"Enter the name of Umpire: ";
		cin.getline(umpire_name,40);
	}
	void put_datau()
	{
		cout<<endl<<"Umpire ID: "<<umpire_id;
		cout<<endl<<"Umpire Name: "<<umpire_name<<endl;
	}
	int umpireid()
	{
		return umpire_id;
	}
	void retlastid()
	{
		cout<<endl<<"Last entered ID: "<<umpire_id;
	}
};
class umpire_data : public umpire{	//Class to store data related to umpires
	public:
		void get_dataud(){
			int temp;
			cout<<endl<<"Enter Umpire ID: ";
			cin>>umpire_id;
			fflush(stdin);
			cin.ignore();
			cout<<endl<<"Enter the name of Umpire: ";
			cin.getline(umpire_name,40);
			fflush(stdin);
			cin.ignore();
			cout<<endl<<"Enter no of matches umpired: ";
			cin>>temp;
			onfieldcount+=temp;
			cout<<endl<<"Enter no of correct decisions: ";
			cin>>temp;
			correctdecision+=temp;
			cout<<endl<<"Enter no of wrong decisions: ";
			cin>>temp;
			wrongdecision+=temp;
		}
		void put_dataud(){
			cout<<endl<<"Umpire ID: "<<umpire_id;
			cout<<endl<<"Umpire Name: "<<umpire_name;
			cout<<endl<<"No of matches umpired: "<<onfieldcount;
			cout<<endl<<"No of correct decision: "<<correctdecision;
			cout<<endl<<"No of wrong decision: "<<wrongdecision<<endl;
		}
		int return_umpid()
		{
			return umpire_id;
		}
		int return_correctdec()
		{
			return correctdecision;
		}
		void nameoftheump()
		{
			cout<<endl<<"Name of the umpire with maximum correct decision: "<<umpire_name;
		}
};
class points{		//Class to store team points and data
		int teamid;
		char t_name[40];
		int point;
		int matches;
		public:
			points()
			{
				point=0;
				matches=0;
			}
			public:
				void addteamr()
				{
					int tempdata;
					cout<<endl<<"Enter team ID: ";
					cin>>teamid;
					fflush(stdin);
					cin.ignore();
					cout<<endl<<"Enter team name: ";
					cin.getline(t_name,40);
					fflush(stdin);
					cin.ignore();
					cout<<endl<<"Enter no of matches played: ";
					cin>>tempdata;
					matches+=tempdata;
					cout<<endl<<"Enter points: ";
					cin>>tempdata;
					point+=tempdata;
				}
				void showrecord()
				{
					cout<<endl<<"Team ID: "<<teamid;
					cout<<endl<<"Team Name: "<<t_name;
					cout<<endl<<"No of matches played: "<<matches;
					cout<<endl<<"Points: "<<point<<endl;
				}
				int returnidt()
				{
					return teamid;
				}
				int returnpoints()
				{
					return point;
				}
				void teamnameshow()
				{
					cout<<endl<<"Team with maximum no of points: "<<t_name;
				}
};
int main() {
	points pt;
    player obj_player, obj_playeri;
    coach c, ci;
    team t, ti;
    data d,di;
    stadium s,si;
    match m;
    umpire um;
    umpire_data umd;
    int option, condition, searchid,l;
    do {
        cout << endl << "					      IPL Cricket Tournament Organizer";
        cout<<endl<<"*************************************************************************************************************************";
        cout<<endl <<"							Dashboard";
        cout<<endl<<"*************************************************************************************************************************";
        cout<<endl<<endl;
        cout << endl << "1)Add Player.			2)Modify Player.		3)List of all players.		4)Specific Player View.";
        cout << endl << endl;
        cout << endl << "5)Add Player info.		6)Update Player info.		7)All Player's Details.		8)Specific Player Details.";
        cout << endl << endl;
        cout << endl << "9)Add Coach info.		10)Modify Coach info.		11)View Coach info.		12)Specific Coach info.";
        cout << endl << endl;
        cout << endl << "13)Add Team info.		14)Modify Team info.		15)View Team info.		16)Add Stadium info.";
        cout << endl << endl;
        cout << endl << "17)Modify Stadium info.		18)View Stadium info.		19)Add Match Data.		20)View Match Data.";
        cout << endl << endl;
        cout << endl <<"21)Add Umpire.			22)View Umpire.			23)Add Umpire Details.		24)Update Umpire Details.";
        cout<<endl<< endl;
        cout<<endl<<"25)View Umpire Details.		26)Team Point Add.		27)Team Point Update.		28)Team Point View.";
		cout<<endl<<endl;
		cout<<endl<<"29)View Match Schedule.		30)View Match Summery till Date.31)Delete player.		32)Delete team.";
		cout<<endl<<endl;
		cout<<endl<<"33)Delete umpire.		34)Delete coach.		35)Delete stadium.		36)Delete player info.";
		cout<<endl<<endl;
        cout << endl << "Enter your option: (Eg. 1,2,3) ";
        cin >> option;
        if(option==1){
        	system("cls");
        	cout<<endl<<"Add Player"<<endl;
        	 pl.open("playerdata",ios::in|ios::binary);
            if(!pl)
            {
                cout<<"Sorry! File can't be opened.";
                exit(1);
            }
            pl.seekg(0);
            pl.read((char*)&obj_playeri,sizeof(obj_playeri));
            while(!pl.eof())
            {
                pl.read((char*)&obj_playeri,sizeof(obj_playeri));
            }
            obj_playeri.idshow();
            pl.close();
            pl.open("playerdata",ios::out|ios::binary|ios::app);
            if(!pl)
            {
                cout<<"Sorry! File can't be opened.";
                exit(0);
            }
            obj_player.get_datap();
            pl.write((char*)&obj_player,sizeof(obj_player));
            pl.close();
            cout << "\nEnter 1 to back to mainmenu.";
            cin >> condition;
        }
        else if(option==2)
        {
        	system("cls");
            cout<<endl<<"Enter Player ID: ";
            cin>>searchid;
            pl.open("playerdata",ios::in|ios::out|ios::binary|ios::ate);
            if(!pl)
            {
                cout<<"Sorry! File can't be opened.";
                exit(0);
            }
            pl.seekg(0);
            int found=0;
            while(pl.read((char*)&obj_player,sizeof(obj_player))&&found==0)
            {
                if(obj_player.retid()==searchid)
                {
                    obj_player.put_datap();
                    cout<<"\n New Value: ";
                    obj_player.get_datap();
                    l=sizeof(obj_player);
                    pl.seekp(-l,ios::cur);
                    pl.write((char*)&obj_player,sizeof(obj_player));
                    found=1;

                }
            }
            obj_player.put_datap();
            pl.close();
            cout << "\nEnter 1 to back to main menu.";
            cin >> condition;
        }
        else if(option==3) {
        	system("cls");
            pl.open("playerdata",ios::in|ios::binary);
            if(!pl)
            {
                cout<<"Sorry! File can't be opened.";
                exit(1);
            }
            pl.seekg(0);
            pl.read((char*)&obj_playeri,sizeof(obj_playeri));
            while(!pl.eof())
            {
                obj_playeri.put_datap();
                pl.read((char*)&obj_playeri,sizeof(obj_playeri));
            }
            pl.close();
            cout << "\nEnter 1 to back to main menu.";
            cin >> condition;
        }
        else if(option==4)
        {
        	system("cls");
            int idm;
            cout<<endl<<"Enter Player ID: ";
            cin>>searchid;
            pl.open("playerdata",ios::in|ios::binary);
            pl.seekg(0);
            pl.read((char*)&obj_playeri,sizeof(player));
            idm=obj_playeri.retid();
            while(!pl.eof())
            {
                if(idm==searchid)
                {
                    obj_playeri.put_datap();
                }
                pl.read((char*)&obj_playeri,sizeof(obj_playeri));
                idm=obj_playeri.retid();
            }
            pl.close();
            cout << "\nEnter 1 to back to main menu.";
            cin >> condition;
        }
        else if(option==5)
        {
        	system("cls");
            dta.open("playerdetails",ios::out|ios::binary|ios::app);
            d.getdatad();
            dta.write((char*)&d,sizeof(d));
            dta.close();
            cout << "\nEnter 1 to back to mainmenu.";
            cin >> condition;
        }
        else if(option==6)
        {
        	system("cls");
            cout<<endl<<"Enter Player ID: ";
            cin>>searchid;
            int got=0;
            dta.open("playerdetails",ios::in|ios::out|ios::binary|ios::ate);
            if(!dta)
            {
            	cout<<endl<<"Sorry! File can't be opened.";
            	exit(1);
			}
            dta.seekg(0);
            while(dta.read((char*)&d,sizeof(d))&&got==0)
            {
                if(d.retiddata()==searchid)
                {
                	d.put_datad();
                    cout<<"\n New Value: ";
                    d.getdatad();
                    l= sizeof(d);
                    dta.seekp(-l,ios::cur);
                    dta.write((char*)&d,sizeof(d));
                    got=1;
                }
            }
            dta.close();
            cout << "\nEnter 1 to back to main menu.";
            cin >> condition;
        }
        else if(option==7)
        {
        	system("cls");
            dta.open("playerdetails",ios::in|ios::binary);
            dta.seekg(0);
            dta.read((char*)&di,sizeof(di));
            while(!dta.eof())
            {
                di.put_datad();
                dta.read((char*)&di,sizeof(di));
            }
            dta.close();
            cout << "\nEnter 1 to back to main menu.";
            cin >> condition;
        }
		else if(option==8){
			system("cls");
			 cout<<endl<<"Enter Player ID: ";
            cin>>searchid;
            dta.open("playerdetails",ios::in|ios::out|ios::binary|ios::ate);
            if(!dta)
            {
            	cout<<endl<<"Sorry! File can't be opened.";
            	exit(1);
			}
			int got=0;
            dta.seekg(0);
            while(dta.read((char*)&d,sizeof(d))&&got==0)
            {
                if(d.retiddata()==searchid)
                {
                	d.put_datad();
                	got=1;
                }
            }
            dta.close();
            cout << "\nEnter 1 to back to main menu.";
            cin >> condition;
		}
        else if(option==9)
        {
        	system("cls");
        	cch.open("coach",ios::in|ios::binary);
            if(!cch)
            {
            	cout<<endl<<"Sorry! File can't be opened.";
            	exit(1);
			}
            cch.seekg(0);
            cch.read((char*)&ci,sizeof(ci));
            while(!cch.eof())
            {
                cch.read((char*)&ci,sizeof(ci));
            }
            ci.showlastid();
            cch.close();
            cch.open("coach",ios::out|ios::binary|ios::app);
            if(!cch)
            {
            	cout<<endl<<"Sorry! File can't be opened.";
            	exit(1);
			}
            c.get_datac();
            cch.write((char*)&c,sizeof(c));
            cch.close();
            cout << "\nEnter 1 to back to mainmenu.";
            cin >> condition;
        }
        else if(option==10)
        {
        	system("cls");
        	cout<<endl<<"Enter Coach ID: ";
        	cin>>searchid;
        	int got1=0;
        	cch.open("coach",ios::in|ios::out|ios::binary|ios::ate);
        	if(!cch)
            {
            	cout<<endl<<"Sorry! File can't be opened.";
            	exit(1);
			}
			cch.seekg(0);
			while(cch.read((char*)&c,sizeof(c))||got1==0)
			{
				if(c.return_coachid()==searchid)
				{
					c.putdatac();
					cout<<endl<<"Enter New Details: ";
					c.get_datac();
					l=sizeof(c);
					cch.seekp(-l,ios::cur);
					cch.write((char*)&c,sizeof(c));
					got1=1;
				}
			}
			c.putdatac();
			cch.close();
			cout << "\nEnter 1 to back to mainmenu.";
            cin >> condition;
		}
        else if(option==11)
        {
        	system("cls");
            cch.open("coach",ios::in|ios::binary);
            if(!cch)
            {
            	cout<<endl<<"Sorry! File can't be opened.";
            	exit(1);
			}
            cch.seekg(0);
            cch.read((char*)&ci,sizeof(ci));
            while(!cch.eof())
            {
                ci.putdatac();
                cch.read((char*)&ci,sizeof(ci));
            }
            cch.close();
            cout << "\nEnter 1 to back to main menu.";
            cin >> condition;
        }
        else if(option==12){
        	system("cls");
        	cout<<endl<<"Enter Coach ID: ";
        	cin>>searchid;
        	int got1=0;
        	cch.open("coach",ios::in|ios::out|ios::binary|ios::ate);
        	if(!cch)
            {
            	cout<<endl<<"Sorry! File can't be opened.";
            	exit(1);
			}
			cch.seekg(0);
			while(cch.read((char*)&c,sizeof(c))||got1==0)
			{
				if(c.return_coachid()==searchid)
				{
					c.putdatac();
					got1=1;
				}
			}
			cch.close();
			cout << "\nEnter 1 to back to mainmenu.";
            cin >> condition;
		}
        else if(option==13)
        {
        	system("cls");
            tm.open("teamdata.dat",ios::out|ios::binary|ios::app);
            if(!tm)
            {
            	cout<<endl<<"File can't be opened.";
            	exit(1);
			}
            t.get_datat();
            tm.write((char*)&t,sizeof(t));
            tm.close();
            cout << "\nEnter 1 to back to main menu.";
            cin >> condition;
        }
        else if(option==14)
        {
        	system("cls");
        	cout<<endl<<"Enter Team ID: ";
        	cin>>searchid;
        	tm.open("teamdata.dat",ios::in|ios::out|ios::binary|ios::ate);
        	if(!tm)
            {
            	cout<<endl<<"File can't be opened.";
            	exit(1);
			}
			tm.seekg(0);
			int got2=0;
			while(tm.read((char*)&t,sizeof(t))||got2==0)
			{
				if(t.return_teamid()==searchid)
				{
					t.put_datat();
					cout<<endl<<"Enter New Data: ";
					t.get_datat();
					l=sizeof(t);
					tm.seekp(-l,ios::cur);
					tm.write((char*)&t,sizeof(t));
					got2=1;
				}
			}
			tm.close();
			cout << "\nEnter 1 to back to main menu.";
            cin >> condition;
		}
        else if(option==15)
        {
        	system("cls");
            tm.open("teamdata.dat",ios::in|ios::binary);
            if(!tm)
            {
            	cout<<endl<<"File can't be opened.";
            	exit(1);
			}
            tm.seekg(0);
            tm.read((char*)&ti,sizeof(ti));
            while(tm)
            {
                ti.put_datat();
                tm.read((char*)&ti,sizeof(ti));
            }
            tm.close();
            cout << "\nEnter 1 to back to main menu.";
            cin >> condition;
        }
        else if(option==16)
        {
        	system("cls");
            sdm.open("stadium",ios::out|ios::binary|ios::app);
            s.getdatas();
            sdm.write((char*)&s,sizeof(s));
            sdm.close();
            cout << "\nEnter 1 to back to main menu.";
            cin >> condition;
        }
        else if(option==17)
        {
        	system("cls");
        	cout<<endl<<"Enter Stadium ID: ";
        	cin>>searchid;
        	sdm.open("stadium",ios::in|ios::out|ios::binary|ios::ate);
        	if(!sdm)
        	{
        		cout<<endl<<"Sorry! File can't be opened.";
        		exit(1);
			}
        	sdm.seekg(0);
        	int got3=0;
        	while(sdm.read((char*)&s,sizeof(s))||got3==0)
        	{
        		if(s.return_stadiumid()==searchid)
        		{
        			s.putdatas();
        			cout<<endl<<"Enter new details: ";
        			s.getdatas();
        			l=sizeof(s);
        			sdm.seekp(-l,ios::cur);
        			sdm.write((char*)&s,sizeof(s));
        			got3=1;
				}
			}
        	sdm.close();
        	cout << "\nEnter 1 to back to main menu.";
            cin >> condition;
		}
        else if(option==18)
        {
        	system("cls");
            sdm.open("stadium",ios::in|ios::binary);
            sdm.seekg(0);
            sdm.read((char*)&si,sizeof(si));
            while(!sdm.eof())
            {
                si.putdatas();
                sdm.read((char*)&si,sizeof(si));
            }
            sdm.close();
            cout << "\nEnter 1 to back to main menu.";
            cin >> condition;
        }
        else if(option==19)
        {
        	system("cls");
        	matchdata.open("matchdata",ios::out|ios::binary|ios::app);
        	m.getdatam();
        	matchdata.write((char*)&m,sizeof(m));
            matchdata.close();
        	cout << "\nEnter 1 to back to main menu.";
            cin >> condition;
		}
		else if(option==20)
		{
			system("cls");
			int idm;
			matchdata.open("matchdata",ios::in|ios::binary);
            if(!matchdata)
            {
            	cout<<endl<<"File can't be opened.";
            	exit(1);
			}
            matchdata.seekg(0);
            matchdata.read((char*)&m,sizeof(m));
            while(matchdata)
            {
                m.putdatam();
            	pl.open("playerdata.dat",ios::in|ios::binary);
            	pl.seekg(0);
            	pl.read((char*)&obj_playeri,sizeof(player));
            	idm=obj_playeri.retid();
            	while(!pl.eof())
            	{
                	if(idm==m.retmid())
                	{
                    	obj_playeri.plname();
                	}
                	pl.read((char*)&obj_playeri,sizeof(obj_playeri));
                	idm=obj_playeri.retid();
            	}
            	pl.close(); 
            	matchdata.read((char*)&m,sizeof(m));
            }
            tm.close();
            matchdata.close();
            cout << "\nEnter 1 to back to main menu.";
            cin >> condition;
		}
		else if(option==21)
		{
			system("cls");
			ump.open("umpire",ios::in|ios::binary);
			if(!ump)
			{
				cout<<endl<<"Sorry! File can't be opened.";
				exit(1);
			}
			ump.seekg(0);
			ump.read((char*)&um,sizeof(um));
			while(ump)
			{
				ump.read((char*)&um,sizeof(um));
			}
			um.retlastid();
			ump.close();
			ump.open("umpire",ios::out|ios::binary|ios::app);
			if(!ump)
			{
				cout<<endl<<"Sorry! File can't be opened.";
				exit(1);
			}
			um.get_datau();
			ump.write((char*)&um,sizeof(um));
			ump.close();
			cout << "\nEnter 1 to back to main menu.";
            cin >> condition;
		}
		else if(option==22)
		{
			system("cls");
			ump.open("umpire",ios::in|ios::binary);
			if(!ump)
			{
				cout<<endl<<"Sorry! File can't be opened.";
				exit(1);
			}
			ump.seekg(0);
			ump.read((char*)&um,sizeof(um));
			while(ump)
			{
				um.put_datau();
				ump.read((char*)&um,sizeof(um));
			}
			ump.close();
			cout << "\nEnter 1 to back to main menu.";
            cin >> condition;
		}
		else if(option==23)
		{
			system("cls");
			umpd.open("umpiredata",ios::out|ios::binary|ios::app);
			if(!umpd)
			{
				cout<<endl<<"Sorry! File can't be opened.";
			}
			umd.get_dataud();
			umpd.write((char*)&umd,sizeof(umd));
			umpd.close();
			cout << "\nEnter 1 to back to main menu.";
            cin >> condition;
		}
		else if(option==24)
		{
			system("cls");
			int umid;
			cout<<endl<<"Enter umpire id:";
			cin>>umid;
			int found=0;
			umpd.open("umpiredata",ios::in|ios::out|ios::binary|ios::ate);
			if(!umpd)
			{
				cout<<endl<<"Sorry! File can't be opened.";
			}
			umpd.seekg(0);
			while(umpd.read((char*)&umd,sizeof(umd))&&found==0)
			{
				if(umd.return_umpid()==umid)
				{
					umd.put_dataud();
					cout<<endl<<"Update Details: ";
					umd.get_dataud();
					l=sizeof(umd);
					umpd.seekp(-l,ios::cur);
					umpd.write((char*)&umd,sizeof(umd));
					found=1;
				}
			}
			umpd.close();
			cout << "\nEnter 1 to back to main menu.";
            cin >> condition;
		}
		else if(option==25)
		{
			system("cls");
			umpd.open("umpiredata",ios::in|ios::binary);
			if(!umpd)
			{
				cout<<endl<<"Sorry! File can't be opened.";
			}
			umpd.seekg(0);
			umpd.read((char*)&umd,sizeof(umd));
			while(umpd)
			{
				umd.put_dataud();
				umpd.read((char*)&umd,sizeof(umd));
			}
			umpd.close();
			cout << "\nEnter 1 to back to main menu.";
            cin >> condition;
		}
		else if(option==26)
		{
			system("cls");
			ptt.open("points",ios::out|ios::binary|ios::app);
			if(!ptt)
			{
				cout<<endl<<"Sorry! File can't be opened.";
				exit(1);
			}
			pt.addteamr();
			ptt.write((char*)&pt,sizeof(pt));
			ptt.close();
			cout << "\nEnter 1 to back to main menu.";
            cin >> condition;
		}
		else if(option==27)
		{
			system("cls");
			int found=0;
			int search;
			cout<<"Enter team ID: ";
			cin>>search;
			int len;
			ptt.open("points",ios::in|ios::out|ios::binary|ios::ate);
			if(!ptt)
			{
				cout<<endl<<"Sorry! File can't be opened.";
				exit(1);
			}
			ptt.seekg(0);
			while(ptt.read((char*)&pt,sizeof(pt))&&found==0)
			{
				if(pt.returnidt()==search)
				{
					pt.showrecord();
					cout<<endl<<"Update details: ";
					len=sizeof(pt);
					ptt.seekp(-len,ios::cur);
					pt.addteamr();
					ptt.write((char*)&pt,sizeof(pt));
					found=1;
				}
			}
			ptt.close();
			cout << "\nEnter 1 to back to main menu.";
            cin >> condition;
		}
		else if(option==28)
		{
			system("cls");
			ptt.open("points",ios::in|ios::binary);
			if(!ptt)
			{
				cout<<endl<<"Sorry! File can't be opened.";
				exit(1);
			}
			ptt.seekg(0);
			ptt.read((char*)&pt,sizeof(pt));
			while(ptt)
			{	pt.showrecord();
				ptt.read((char*)&pt,sizeof(pt));
			}
			ptt.close();
			cout << "\nEnter 1 to back to main menu.";
            cin >> condition;
		}
		else if(option==29)
		{
			system("cls");
			int count=1,date1=1,date2=1,date3=1;
			string teams[]={"MI","RCB","DC","CSK","KKR","RR","KXIP","SRH"};
			for(int i=0;i<8;i++)
			{
				for(int j=0;j<8;j++)
				{
					if(i==j)
					{
						continue;
					}
					if(date2>=30)
					{
						cout<<"Match No: "<<count<<endl;
						cout<<"Date : "<<"May "<<date3<<", 2019"<<endl;
						cout<<teams[i]<<" VS "<<teams[j]<<endl;
						count++;
						date3++;
					}
					else if(date1>=30)
					{
						cout<<"Match No: "<<count<<endl;
						cout<<"Date : "<<"April "<<date2<<", 2019"<<endl;
						cout<<teams[i]<<" VS "<<teams[j]<<endl;
						count++;
						date2++;
					}
					else{
					cout<<"Match No: "<<count<<endl;
					cout<<"Date : "<<"March "<<date1<<", 2019"<<endl;
					cout<<teams[i]<<" VS "<<teams[j]<<endl;
					count++;
					date1++;
				}
				}
			}
			cout << "\nEnter 1 to back to main menu.";
            cin >> condition;
		}
		else if(option==30)
		{
			system("cls");
			int greater;
			cout<<endl<<"Match Summery Till Date: ";
			dta.open("playerdetails",ios::in|ios::binary);
            dta.seekg(0);
            dta.read((char*)&di,sizeof(di));
            greater=di.retscore();
            while(dta)
            {
                dta.read((char*)&di,sizeof(di));
                if(di.retscore()>greater)
            	{
            		greater=di.retscore();
				}
            }
            dta.close();
            dta.open("playerdetails",ios::in|ios::binary);
            dta.seekg(0);
            while(dta)
            {
            	if(di.retscore()==greater)
            	{
            		di.maxrunplayer();
            		break;
				}
                dta.read((char*)&di,sizeof(di));
            }
            dta.close();
            dta.open("playerdetails",ios::in|ios::binary);
            dta.seekg(0);
            dta.read((char*)&di,sizeof(di));
            greater=di.ret4();
            while(dta)
            {
                dta.read((char*)&di,sizeof(di));
                if(di.ret4()>greater)
            	{
            		greater=di.ret4();
				}
            }
            dta.close();
            dta.open("playerdetails",ios::in|ios::binary);
            dta.seekg(0);
            while(!dta.eof())
            {
            	if(di.ret4()==greater)
            	{
            		di.max4();
            		break;
				}
                dta.read((char*)&di,sizeof(di));
            }
            dta.close();
            dta.open("playerdetails",ios::in|ios::binary);
            dta.seekg(0);
            dta.read((char*)&di,sizeof(di));
            int greater1=di.ret6();
            while(dta)
            {
                dta.read((char*)&di,sizeof(di));
                if(di.ret6()>greater1)
            	{
            		greater1=di.ret6();
				}
            }
            dta.close();
            dta.open("playerdetails",ios::in|ios::binary);
            dta.seekg(0);
            while(!dta.eof())
            {
            	if(di.ret6()==greater1)
            	{
            		di.max6();
            		break;
				}
                dta.read((char*)&di,sizeof(di));
            }
            dta.close();
            dta.open("playerdetails",ios::in|ios::binary);
            dta.seekg(0);
            dta.read((char*)&di,sizeof(di));
            greater1=di.retw();
            while(dta)
            {
                dta.read((char*)&di,sizeof(di));
                if(di.retw()>greater1)
            	{
            		greater1=di.retw();
				}
            }
            dta.close();
            dta.open("playerdetails",ios::in|ios::binary);
            dta.seekg(0);
            while(!dta.eof())
            {
            	if(di.retw()==greater1)
            	{
            		di.maxwicketplayer();
            		break;
				}
                dta.read((char*)&di,sizeof(di));
            }
            dta.close();
            dta.open("playerdetails",ios::in|ios::binary);
            dta.seekg(0);
            dta.read((char*)&di,sizeof(di));
            greater1=di.retcent();
            while(dta)
            {
                dta.read((char*)&di,sizeof(di));
                if(di.retcent()>greater1)
            	{
            		greater1=di.retcent();
				}
            }
            dta.close();
            dta.open("playerdetails",ios::in|ios::binary);
            dta.seekg(0);
            while(!dta.eof())
            {
            	if(di.retcent()==greater1)
            	{
            		di.maxcentplayer();
            		break;
				}
                dta.read((char*)&di,sizeof(di));
            }
            dta.close();
            umpd.open("umpiredata",ios::in|ios::binary);
			if(!umpd)
			{
				cout<<endl<<"Sorry! File can't be opened.";
			}
			umpd.seekg(0);
			umpd.read((char*)&umd,sizeof(umd));
			greater=umd.return_umpid();
			while(umpd)
            {
                umpd.read((char*)&umd,sizeof(umd));
                if(umd.return_umpid()>greater)
            	{
            		greater=umd.return_umpid();
				}
            }
			umpd.close();
			umpd.open("umpiredata",ios::in|ios::binary);
			if(!umpd)
			{
				cout<<endl<<"Sorry! File can't be opened.";
			}
			umpd.seekg(0);
			umpd.read((char*)&umd,sizeof(umd));
			while(umpd)
            {
                if(umd.return_umpid()==greater)
            	{
            		umd.nameoftheump();
            		break;
				}
				umpd.read((char*)&umd,sizeof(umd));
            }
			umpd.close();
			ptt.open("points",ios::in|ios::binary);
			if(!ptt)
			{
				cout<<endl<<"Sorry! File can't be opened.";
				exit(1);
			}
			ptt.seekg(0);
			ptt.read((char*)&pt,sizeof(pt));
			greater=pt.returnpoints();
			while(ptt)
			{	ptt.read((char*)&pt,sizeof(pt));
				if(pt.returnidt()>greater)
				{
					greater=pt.returnidt();
				}
			}
			ptt.close();
			ptt.open("points",ios::in|ios::binary);
			if(!ptt)
			{
				cout<<endl<<"Sorry! File can't be opened.";
				exit(1);
			}
			ptt.seekg(0);
			ptt.read((char*)&pt,sizeof(pt));
			while(ptt)
			{	if(pt.returnpoints()==greater)
				{
					pt.teamnameshow();
					break;
				}
				ptt.read((char*)&pt,sizeof(pt));
			}
			ptt.close();
        	cout << "\nEnter 1 to back to main menu.";
            cin >> condition;
		}
		else if(option==31)
		{
			system("cls");
			int searchid;
			cout<<endl<<"Enter player ID: ";
			cin>>searchid;
			pl.open("playerdata",ios::in|ios::binary);
			plc.open("temp",ios::out|ios::binary|ios::app);
            if(!pl)
            {
                cout<<"Sorry! File can't be opened.";
                exit(1);
            }
            if(!plc)
            {
                cout<<"Sorry! File can't be opened.";
                exit(1);
            }
            pl.seekg(0);
          	pl.read((char*)&obj_playeri,sizeof(obj_playeri));
            while(pl)
            {
            	if(obj_playeri.retid()==searchid)
            	{
            		cout<<endl<<"Deleted";
            		pl.read((char*)&obj_playeri,sizeof(obj_playeri));
				}
				else{
                obj_playeri.put_datap();
                plc.write((char*)&obj_playeri,sizeof(obj_playeri));
                pl.read((char*)&obj_playeri,sizeof(obj_playeri));
            }
			}
            pl.close();
            plc.close();
            remove("playerdata");
            rename("temp","playerdata");
            dta.open("playerdetails",ios::in|ios::binary);
			dtac.open("temp",ios::out|ios::binary|ios::app);
            if(!dta)
            {
                cout<<"Sorry! File can't be opened.";
                exit(1);
            }
            if(!dtac)
            {
                cout<<"Sorry! File can't be opened.";
                exit(1);
            }
            dta.seekg(0);
          	dta.read((char*)&d,sizeof(d));
            while(dta)
            {
            	if(d.retiddata()==searchid)
            	{
            		cout<<endl<<"Deleted";
            		dta.read((char*)&d,sizeof(d));
				}
				else{
                d.put_datad();
                dtac.write((char*)&d,sizeof(d));
                dta.read((char*)&s,sizeof(s));
            }
			}
            dta.close();
            dtac.close();
            remove("playerdetails");
            rename("temp","playerdetails");
            cout << "\nEnter 1 to back to main menu.";
            cin >> condition;
		}
		else if(option==32)
		{
			system("cls");
			int searchid;
			cout<<endl<<"Enter team ID: ";
			cin>>searchid;
			tm.open("teamdata.dat",ios::in|ios::binary);
			tmc.open("temp.dat",ios::out|ios::binary|ios::app);
            if(!tm)
            {
                cout<<"Sorry! File can't be opened.";
                exit(1);
            }
            if(!tmc)
            {
                cout<<"Sorry! File can't be opened.";
                exit(1);
            }
            tm.seekg(0);
          	tm.read((char*)&t,sizeof(t));
            while(tm)
            {
            	if(t.return_teamid()==searchid)
            	{
            		cout<<endl<<"Deleted";
            		tm.read((char*)&t,sizeof(t));
				}
				else{
                t.put_datat();
                tmc.write((char*)&t,sizeof(t));
                tm.read((char*)&t,sizeof(t));
            }
			}
            tm.close();
            tmc.close();
            remove("teamdata.dat");
            rename("temp.dat","teamdata.dat");
            cout << "\nEnter 1 to back to main menu.";
            cin >> condition;
		}
		else if(option==33)
		{
			system("cls");
			int searchid;
			cout<<endl<<"Enter umpire ID: ";
			cin>>searchid;
			ump.open("umpire",ios::in|ios::binary);
			umpc.open("temp",ios::out|ios::binary|ios::app);
            if(!ump)
            {
                cout<<"Sorry! File can't be opened.";
                exit(1);
            }
            if(!umpc)
            {
                cout<<"Sorry! File can't be opened.";
                exit(1);
            }
            ump.seekg(0);
          	ump.read((char*)&um,sizeof(um));
            while(ump)
            {
            	if(um.umpireid()==searchid)
            	{
            		cout<<endl<<"Deleted";
            		ump.read((char*)&um,sizeof(um));
				}
				else{
                um.put_datau();
                umpc.write((char*)&um,sizeof(um));
                ump.read((char*)&um,sizeof(um));
            }
			}
            ump.close();
            umpc.close();
            remove("umpire");
            rename("temp","umpire");
            cout << "\nEnter 1 to back to main menu.";
            cin >> condition;
		}
		else if(option==34)
		{
			system("cls");
			int searchid;
			cout<<endl<<"Enter coach ID: ";
			cin>>searchid;
			cch.open("coach",ios::in|ios::binary);
			cchc.open("temp",ios::out|ios::binary|ios::app);
            if(!cch)
            {
                cout<<"Sorry! File can't be opened.";
                exit(1);
            }
            if(!cchc)
            {
                cout<<"Sorry! File can't be opened.";
                exit(1);
            }
            cch.seekg(0);
          	cch.read((char*)&c,sizeof(c));
            while(cch)
            {
            	if(c.return_coachid()==searchid)
            	{
            		cout<<endl<<"Deleted";
            		cch.read((char*)&c,sizeof(c));
				}
				else{
                c.putdatac();
                cchc.write((char*)&c,sizeof(c));
                cch.read((char*)&c,sizeof(c));
            }
			}
            cch.close();
            cchc.close();
            remove("coach");
            rename("temp","coach");
            cout << "\nEnter 1 to back to main menu.";
            cin >> condition;	
		}
		else if(option==35)
		{
			system("cls");
			int searchid;
			cout<<endl<<"Enter stadium ID: ";
			cin>>searchid;
			sdm.open("stadium",ios::in|ios::binary);
			sdmc.open("temp",ios::out|ios::binary|ios::app);
            if(!sdm)
            {
                cout<<"Sorry! File can't be opened.";
                exit(1);
            }
            if(!sdmc)
            {
                cout<<"Sorry! File can't be opened.";
                exit(1);
            }
            sdm.seekg(0);
          	sdm.read((char*)&s,sizeof(s));
            while(sdm)
            {
            	if(s.return_stadiumid()==searchid)
            	{
            		cout<<endl<<"Deleted";
            		sdm.read((char*)&s,sizeof(s));
				}
				else{
                s.putdatas();
                sdmc.write((char*)&s,sizeof(s));
                sdm.read((char*)&s,sizeof(s));
            }
			}
            sdm.close();
            sdmc.close();
            remove("stadium");
            rename("temp","stadium");
            cout << "\nEnter 1 to back to main menu.";
            cin >> condition;	
		}
		else if(option==36)
		{
			system("cls");
			int searchid;
			cout<<endl<<"Enter player ID: ";
			cin>>searchid;
			dta.open("playerdetails",ios::in|ios::binary);
			dtac.open("temp",ios::out|ios::binary|ios::app);
            if(!dta)
            {
                cout<<"Sorry! File can't be opened.";
                exit(1);
            }
            if(!dtac)
            {
                cout<<"Sorry! File can't be opened.";
                exit(1);
            }
            dta.seekg(0);
          	dta.read((char*)&d,sizeof(d));
            while(dta)
            {
            	if(d.retiddata()==searchid)
            	{
            		cout<<endl<<"Deleted";
            		dta.read((char*)&d,sizeof(d));
				}
				else{
                d.put_datad();
                dtac.write((char*)&d,sizeof(d));
                dta.read((char*)&s,sizeof(s));
            }
			}
            dta.close();
            dtac.close();
            remove("playerdetails");
            rename("temp","playerdetails");
            cout << "\nEnter 1 to back to main menu.";
            cin >> condition;	
		}
		else if(option==37)
		{
			system("cls");
			cout<<endl<<"Schedule from Quarter Final to Final: "<<endl;
			int count=0,showcount;
			matchdata.open("matchdata",ios::in|ios::binary);
            if(!matchdata)
            {
            	cout<<endl<<"File can't be opened.";
            	exit(1);
			}
            matchdata.seekg(0);
    		matchdata.read((char*)&m,sizeof(m));
            while(matchdata)
            {
                count++;
                matchdata.read((char*)&m,sizeof(m));
            }
            matchdata.close();
            showcount=count-1;
            cout<<endl<<"Schedule for Quarter Final, Semi Final and Final";
            cout<<endl<<"No of matches till date: "<<showcount;
           	if(showcount<62)
            {
            	if(showcount<=60)
            	{
					if(showcount<=56)
	            	{
		            	cout<<endl<<"Quarter Final: Awaiting";
		            	cout<<endl<<"Semi Final: Awaiting";
		            	cout<<endl<<"Final: Awaiting";
					}
					else
					{
							cout<<endl<<"Semi Final: Awaiting.";
					}
				}
				else
				{
					cout<<endl<<"Final: Awaiting.";
				}
			}
            cout << "\nEnter 1 to back to main menu.";
            cin >> condition;
		}
    }while(condition==1);
    return 0;
}
