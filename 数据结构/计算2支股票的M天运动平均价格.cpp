#include<iostream>
#include<algorithm>
using namespace std;

struct Share
{
	int year;
	int month;
	int day;
	string type; //开\收盘
	int s1;
	int s2;
};

bool cmp(const Share &a, const Share &b)
{
	if(a.year < b.year)
    {
		return a.year < b.year;
	}
    else
    {
		if(a.month < b.month)
        {
			return a.month < b.month;
		}
        else
        {
			return a.day < b.day;
		}
	}
}

class SeqList
{
	Share *list;
	Share *openList; 
	Share *closeList; 
	int N; 
	int M; 
	int openNum; 
	int closeNum; 
public:
	SeqList(); 
	~SeqList();
	void findAVG();
};
SeqList::SeqList()
{
	openNum = 0;
	closeNum = 0;
	char ch;
	cin >> N >> M;
	list = new Share[N];
	for(int i=0; i<N; i++)
    {
		cin >> list[i].year >> ch >> list[i].month >> ch >> list[i].day
			>> list[i].type >> list[i].s1 >> list[i].s2; 
		if(list[i].type == "open")
        {
			openNum++;
		}
        else
        {
			closeNum++;
		}
	}
	sort(list, list+N, cmp); 
}
SeqList::~SeqList()
{
	delete[] list;
	delete[] openList;
	delete[] closeList;
}
void SeqList::findAVG()
{
	openList = new Share[openNum];
	closeList = new Share[closeNum];
	int j = 0, k = 0;
	for(int i=0; i<N; i++)
    {
		if(list[i].type == "open")
        {
			openList[j++] = list[i];
		}
        else
        {
			closeList[k++] = list[i];
		}
	} 
	int avgS1, avgS2;

    //open
	for(int i=M-1; i<openNum; i++)
    {
		avgS1 = openList[i].s1;
		avgS2 = openList[i].s2;
		k = M-1;
		j = i-1;
		while(k--)
        {
			avgS1 += openList[j].s1;
			avgS2 += openList[j].s2;
			j--;
		}
		avgS1 /= M;
		avgS2 /= M;
		cout << openList[i].year << '/' << openList[i].month << '/'
			 << openList[i].day << ' ' << openList[i].type << ' '
			 << avgS1 << ' ' << avgS2 << endl;
	} 
    
    //close
	for(int i=M-1; i<closeNum; i++)
    {
		avgS1 = closeList[i].s1;
		avgS2 = closeList[i].s2;
		k = M-1;
		j = i-1;
		while(k--){
			avgS1 += closeList[j].s1;
			avgS2 += closeList[j].s2;
			j--;
		}
		avgS1 /= M;
		avgS2 /= M;
		cout << closeList[i].year << '/' << closeList[i].month << '/'
			 << closeList[i].day << ' ' << closeList[i].type << ' '
			 << avgS1 << ' ' << avgS2 << endl;
	} 
}

int main()
{
	SeqList list;
	list.findAVG();
	return 0;
}
