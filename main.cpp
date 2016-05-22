#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stack>
#include <string.h>
#include "Cell.h"

using namespace std;

int main(){
	
	int n,m,i,j,k,l;
	char q,name[30],outname[30];
	Cell cells[100][100],nowCell;
	stack <Cell> s;
	ifstream infile;
	ofstream outfile;
	
	//diavazw apo to xrhsth ta onomata twn arxeiwn eidosou kai exodou
	cout<<"Give the name of maze file('name'.txt): ";
	cin>>name;
	infile.open(name);
	if(!infile.is_open()){ //se periptwsh pou einai lathos to onoma arxeiou emfanizw mhnyma lathous kai termatizei to programma
		cout<<"Can't open file with this name!"<<endl;
		exit(1);
	}
	cout<<endl<<"Give the name of mazeout file('nameout'.txt): ";
	cin>>outname;
	cout<<endl;
	outfile.open(outname);

	//diavazw stiles kai grammes
	infile>>n>>m;
	infile.get(q); //diavazw telos grammis
	
	//ftiaxnw to pinaka apo cells pou diavazw apo to arxeio eisodou
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			infile.get(q);
			cells[i][j].i=i;
			cells[i][j].j=j;
			cells[i][j].c=q;
		}
		infile.get(q); //telos grammis
	}
	

	s.push(cells[1][0]); //kanw push to shmeio eisodou tou maze
	while(!(s.empty())){
		
		nowCell=s.top(); //nowCell einai to cell ekeinhs ths stigmhs. Kai edw to kanw iso me thn koryfi tis stoivas
		k=nowCell.geti();
		l=nowCell.getj();
		cells[k][l].c='*'; //kanw iso me * to trexon cell
		
		if((k==n-2) && (l == m-1)){ //an ftasoume sto shmeio exodou apo ton maze tote vgainoume giati vrethike h lysi
			break;
		}
		if(cells[k][l+1].c==' '){ //an exei keno paw dexia
			l++;
			s.push(cells[k][l]);}
		else if(cells[k+1][l].c==' '){ //an exei keno paw katw
	  		k++;
			s.push(cells[k][l]);}
		else if(cells[k][l-1].c==' '){ //an exei keno paw aristera
			l--;
			s.push(cells[k][l]);}
		else if(cells[k-1][l].c==' '){ //an exei keno paw panw
			k--;
			s.push(cells[k][l]);}
		else if((cells[k][l+1].c!=' ') && (cells[k+1][l].c!=' ') && (cells[k][l-1].c!=' ') && (cells[k-1][l].c!=' ')){ //alliws kanw to cell=. kai pop
			cells[k][l].c='.';
			s.pop();
		}
			
	}
	
	//grafw sto arxeio exodou to apotelesma tou maze
	outfile<<n<<" "<<m<<endl;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			outfile<<cells[i][j].c;
		}
		outfile<<endl;
	}
	
	
	infile.close(); //close files
	outfile.close();
	return 0;
}
