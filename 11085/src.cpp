#include <bits/stdc++.h>

using namespace std;

vector<unsigned long long int> v={577094088726155265,1153493525606703105,292736725095563265,297246382237958145,1170937021957408770,585608706247364610,297378317328191490,1154188177435598850,1170944703579824130,576760369759141890,297246377942990850,594492760197726210,2308097558079078660,2308165184214142980,90080928227004420,2341874039636627460,2306476332348870660,594476800348921860,1188959103087681540,612490718627373060,162147728544505860,90090134523355140,148689190832316420,577094139745673220,1170937037029646340,2308095979406114820,1153211915263164420,1153519644301623300,2307039288603181320,162134124219334920,4612813157433344520,1153343854582170120,76702068663910920,297378317462405640,2306970283786895880,4616194020941496840,4612952664681029640,1154048778945175560,148689160817877000,297239845296750600,2306142087114145800,9224499173746819080,180179173830049800,1170938239645745160,297240049576149000,2306476332274450440,306247523977658640,2307039286597255440,577094088726151440,4611972441743819280,81205549035160080,324268244160479760,2307039312249618960,4613940567557080080,585608698710262800,153123761862738960,146402722084634640,297378321619042320,2306970558522343440,9225624953896976400,612490666550902800,153263142016139280,4612284169950101520,297240049324949520,594480098649833760,612507158709273120,292874747648148000,577164509538485280,1170938138646873120,4613940088131355680,9223943788270978080,4612257770917332000,1153343751469401120,576760369259742240,1153625196482004000,306247523708766240,288582290739693600,9223952596195084320,292736724579125280,292804348952608800,1153493390239990080,2306987051079696960,1188959102083007040,577041844735640640,585469119831213120,2306970558656546880,1154048643611887680,577164577201197120,2306986776201790080,2308165182134682240,594492752125822080,1170938239645714560};

int dist(unsigned long long int a,unsigned long long int b)
{
	unsigned long long int f=1;
	int s=0;
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
		{
			unsigned long long int t=(f<<(i*8+j));
			if(((b&t))&&((a&t)==(b&t)))
				s++;
		}
	return 7-s;
}
			

int solution(vector<int>& a)
{
	unsigned long long int f=1,b=0;
	for(int i=0;i<8;i++)
		b=b|(f<<(i*8+a[i]-1));
	int m=10;
	for(auto x:v)
	{
		int d=dist(x,b);
		if(d<m)
			m=d;
	}
	return m;
}
		

int main()
{
	int n,c=1;
	while(cin>>n)
	{
		vector<int> a={n};
		for(int i=0;i<7;i++)
		{
			int b;
			cin>>b;
			a.push_back(b);
		}
		int s = solution(a)+1;
		cout<<"Case "<<c++<<": ";
		cout<<s<<endl;
	}
	return 0;
}
