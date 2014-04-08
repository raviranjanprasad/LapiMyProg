#include<iostream>

using namespace std;

class Matrix{
public:
	//Matrix(int row,int col);
	Matrix(int row=0, int col=0,int **ptr=0):m_row(row),m_col(col),m_ptr(ptr)
	{
		if(m_ptr == NULL){
		   m_ptr = new int*[m_row];
		   for(int i=0;i<m_row;i++){
                    	m_ptr[i] =  new int[m_col];
        	   }

		}
         };
        void Input();
	void Display();
	~Matrix();
private:
	int **m_ptr;
	int m_row;
	int m_col;
};


/*Matrix::Matrix(int row, int col){
	m_row = row; m_col = col;	
	m_ptr = new int*[m_row];
        for(int i=0;i<m_row;i++){
                m_ptr[i] =  new int[m_col];
        }

}*/
void Matrix::Input(){
	/*m_ptr = new int*[m_row];
	for(int i=0;i<m_col;i++){
		m_ptr[i] =  new int[m_col];
	}*/
	for(int i=0;i<m_row;i++){
		for(int j=0;j<m_col;j++){
			m_ptr[i][j] = i + j;
		}
	}
}

void Matrix::Display(){
	for(int i=0;i<m_row;i++){
                for(int j=0;j<m_col;j++){
                        cout <<" "<< m_ptr[i][j]<<" ";
                }
		cout<<endl;	
        }

}

Matrix::~Matrix(){
	for(int i=0;i<m_row;i++){
			delete [] m_ptr[i];
	}
}


int main(){
	Matrix a(4,5);
	a.Input();
	a.Display();
	cout << endl;
	return 0;
}
