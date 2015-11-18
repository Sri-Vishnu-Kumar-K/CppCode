#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<deque>
#include<vector>
#include<queue>
#include<sstream>
#include<fstream>
#include<time.h>
using namespace std;
string getInput(char file[]){
    stringstream temp;
    ifstream in(file);
    if(!in.is_open()){
        cerr<<"Unable to open file"<<endl;
        exit(0);
    }
    temp << in.rdbuf();
    string a(temp.str());
    return a;
}
struct candidate{
    string st;
    int count;
};
struct node{
    string var;
    int freq;
    node* l;
    node* r;
    string code;
};
node* getNode(){
    node *temporary = new node();
    temporary->var="";
    temporary->freq = 0;
    temporary->l = NULL;
    temporary->r = NULL;
    return temporary;
}
class compare{
public:
    bool operator()(node *l,node *r){
        return l->freq>r->freq;
    }
};
struct codes{
    string var;
    string code;
    int freq;
};
vector<codes>huff;
void printCodes(node *h,string code){
    if(h==NULL){
        return;
    }
    if(h->l==NULL&&h->r==NULL){
        h->code = code;
        codes temp;
        temp.var = h->var;
        temp.code = h->code;
        temp.freq = h->freq;
        huff.push_back(temp);
        return;
    }
    if(h->l){
        printCodes(h->l,code+"0");
    }
    if(h->r){
        printCodes(h->r,code+"1");
    }
    return ;
}
bool compareator(codes a, codes b){
    return (a.var).length()>(b.var).length();
}
struct orderCode{
    string code;
    int ind;
};
bool funct(orderCode a,orderCode b){
    return a.ind<b.ind;
}
int main(int argc,char* argv[]){
    double percent;
    char *file;
    clock_t start,e;
    start = clock();
    if (argc != 3) {
        cerr<<"<usage> : /a.out input minsup"<<endl;
        exit(0);
    } else {
            percent = atof(argv[2]);
            file = argv[1];

    }
    string a;
    a=getInput(file);//Redo and check how to do this.
	int minsup = percent*a.length()/100;
	cout<<"Min support: "<<minsup<<endl;
    cout<<"Creating Hash.."<<endl;
    deque<int>q[128];
    cout<<"Size of the file : "<<a.length()<<endl;
    for(long i=0;i<a.length();i++){
       q[a[i]].push_back(i);
    }
    cout<<"Hash created :)"<<endl;
    deque<candidate>c;
    deque<candidate>l[100];
    cout<<"L is created"<<endl;
    vector<bool>deletedValues;
    for(int i=0;i<a.length();i++){
        deletedValues.push_back(0);
    }
    cout<<"Bool is created"<<endl;
    int countOfc = 0;
    for(int i=0;i<128;i++){
        if(!q[i].empty()){
            candidate tempo;
            tempo.st= i;
            tempo.count = q[i].size();
            l[countOfc].push_back(tempo);
        }
    }
    cout<<"L1"<<endl;
    countOfc++;
    for(int i=0;i<a.length()-1;i++){
        string temp ;
        temp = a.at(i);
        string temp1;
        temp1 = a.at(i+1);
        temp.append(temp1);
        deque<candidate>::iterator it1 = c.begin();
        while(it1!=c.end()){
            if(it1->st==temp){
                it1->count++;
                break;
            }
            it1++;
        }
        if(it1==c.end()){
            candidate tempo;
            tempo.st = temp;
            tempo.count = 1;
            c.push_back(tempo);
        }
    }
    cout<<"L2"<<endl;
    deque<candidate>::iterator iter = c.begin();
    while(iter!=c.end()){
        if(iter->count>=minsup){
            candidate temp = *iter;
            l[countOfc].push_back(temp);
        }
        iter++;
    }
    countOfc++;
    while(countOfc<a.length() && !l[countOfc-1].empty()){
        //cout<<"Count of c is "<<countOfc<<endl;
        deque<candidate>::iterator it1 = l[countOfc-1].begin();
        while(it1!=l[countOfc-1].end()){
            deque<candidate>::iterator it2 = l[countOfc-1].begin();
            while(it2!=l[countOfc-1].end()){
                if(it1!=it2){
                    int flag = 0;
                    for(int i = 0; i<=countOfc-2;i++){
                        if((it1->st).at(i)!=(it2->st).at(i+1)){
                            flag = 1;
                        }
                    }
                    if(flag == 0){
						//cout<<"hi this is vishal"<<endl;
                        string temp1 = it1->st;
                        string temp2 = it2->st;
                        string temp3;
                        temp3 = temp1.at(temp1.length()-1);
                        temp2.append(temp3);
                        deque<int>::iterator it3;
                        int counter = 0;
                        it3 = q[temp2.at(0)].begin();
                        while(it3 != q[temp2.at(0)].end()){
                            int ind= *it3;
                            int flag = 0;
                            for(int j=0;j<temp2.length()&&ind+j<a.length();j++){
                                if(a.at(ind+j)!=temp2.at(j)){
                                    flag = 1;
                                    break;
                                }
                            }
                            if(flag == 0){
                                counter++;
                            }
                            it3++;
                        }
                        if(counter>=minsup){
                      		candidate temp;
                            temp.st = temp2;
                            temp.count = counter;
                            l[countOfc].push_back(temp);
                        }
                    }
                }
                it2++;
            }
            it1++;
        }
        cout<<"L"<<countOfc+1<<endl;
        countOfc++;
    }
    countOfc--;
    countOfc--;
    cout<<"Done here too"<<endl;
    int k = 0;
    int noOfOriginalPatterns =0;
    for(int i=countOfc;i>=0;i--){
        deque<candidate>::iterator iter1;
        iter1 = l[i].begin();
        noOfOriginalPatterns+=l[i].size();
        while(iter1!=l[i].end()){
            string temp = iter1->st;
            int actCount = 0;
            deque<int>::iterator iter2;
            iter2 = q[temp.at(0)].begin();
            while(iter2!=q[temp.at(0)].end()){
                int ind = *iter2;
                if(deletedValues.at(ind)==0){
                    bool flag = false;
                    for(int j = 0;j<temp.length();j++){
                        if(a[ind+j]!=temp.at(j)||deletedValues.at(ind+j)==1){
                            flag = true;
                            break;
                        }
                    }
                    if(flag == false){
                        for(int j=0;j<temp.length()&&ind+j<a.length();j++){
                            deletedValues[ind+j]=1;
                        }
                        actCount++;
                    }
                }
                iter2++;
            }
            iter1->count = actCount;
            if(iter1->count>0){
                k++;
            }
            iter1++;
        }
    }
    cout<<"No of original patterns:"<<noOfOriginalPatterns<<endl;
    cout<<"PtoPdash done"<<endl;
    candidate pq[k+1];
    k = 0;
	ofstream pat("patterns.txt");
    for(int j = 0;j<=countOfc;j++){
        deque<candidate>::iterator it = l[j].begin();
        pat<<"L"<<j+1<<endl;
        while(it!=l[j].end()){
            if(it->count>0){
                pat<<it->st<<" "<<it->count<<endl;
                pq[k]=*it;
                k++;
            }
            it++;
        }
    }
	pat.close();
    cout<<"No of modified patterns:"<<k<<endl;
    priority_queue<node*,vector<node*>,compare> minHeap;
    node *head = NULL,*ptr1=NULL,*ptr2=NULL;
    for(int i=0;i<k;i++){
        node *tempor = getNode();
        tempor->var = pq[i].st;
        tempor->freq = pq[i].count;
        minHeap.push(tempor);
    }
    while(minHeap.size()>1){
        ptr1 = minHeap.top();
        minHeap.pop();
        ptr2 = minHeap.top();
        minHeap.pop();
        node *tempor = getNode();
        tempor->freq = ptr1->freq+ptr2->freq;
        tempor->l = ptr1;
        tempor->r = ptr2;
        minHeap.push(tempor);
    }
    head = minHeap.top();
    minHeap.pop();
    string code;
    printCodes(head,code);
    cout<<"Huffman Encoding Complete"<<endl;
    vector<codes>::iterator check = huff.begin();
    sort(huff.begin(),huff.end(),compareator);
    cout<<"sorting done"<<endl;
    //bool visited[a.length()];
    for(int i=0;i<a.length();i++){
        deletedValues[i] = false;
    }
    vector<orderCode>fin;
    ofstream codeTable("codeTable.txt",ios::binary);
    int codeTableSize =0;
    while(check!=huff.end()){
        codeTable<<check->var<<" "<<check->code<<endl;
        codeTableSize += (check->var).length()+((check->code).length()/8);
        string temp = check->var;
        deque<int>::iterator order;
        order = q[temp.at(0)].begin();
        while(order!=q[temp.at(0)].end()){
            int ind = *order;
            bool flag = false;
            for(int j = 0;j<temp.length()&&ind+j<a.length();j++){
                if(a.at(ind+j)!=temp.at(j)||deletedValues[ind+j]==true){
                    flag = true;
                    break;
                }
            }
            if(flag == false){
                for(int t = 0;t<temp.length()&&ind+t<a.length();t++){
                    deletedValues[ind+t]=true;
                }
                orderCode tempo;
                tempo.code=check->code;
                tempo.ind = ind;
                fin.push_back(tempo);
            }
            order++;
        }
        check++;
    }
    sort(fin.begin(),fin.end(),funct);
    codeTable.close();
    vector<orderCode>::iterator finit = fin.begin();
    string encoded;
    while(finit != fin.end()){
        encoded += finit->code;
        finit++;
    }
    ofstream encodedString("encoded.txt",ios::binary);
    encodedString<<encoded;
    encodedString.close();
    cout<<"Encoded size of bits:"<<encoded.size()/8<<endl;
	cout<<"Encoded size of codeTable"<<codeTableSize<<endl;
    cout<<"String encoding complete"<<endl;
    string decode;
    string tem;
    vector<string>orderofwords;
    cout<<"Code table size"<<codeTableSize<<endl;
    for(int i=0;i<encoded.length();i++){
        tem +=encoded.at(i);
        check = huff.begin();
        while(check!=huff.end()){
            if(check->code==tem){
                orderofwords.push_back(check->var);
                tem = "";
            }
            check++;
        }
    }
    vector<string>::iterator decodedit;
    decodedit = orderofwords.begin();
    while(decodedit!=orderofwords.end()){
        decode+=*decodedit;
        decodedit++;
    }
    cout<<"Compression ratio : "<<(float)a.length()/((encoded.length()/8)+codeTableSize)<<endl;
    ofstream decodedString("decodedString.txt");
    decodedString<<decode;
    decodedString.close();
    cout<<"Decoding complete"<<endl;
    e = clock();
    cout<<"Total time"<<(double)(e-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
