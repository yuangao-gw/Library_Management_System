#include<iostream.h>
#include<conio.h> //����̨������������ĺ���
#include<fstream.h>//�ļ���
#include<iomanip.h> //�������������ʽ
#include<string.h>
#include<ctime>
#include<stdio.h>
#include<stdlib.h>

const int Maxr = 100;//���Ķ�����
const int Maxb = 100; //����ͼ����
const int Maxbor = 5; //ÿλ�����������
const int MaxDate = 1000; //��־��¼����

typedef struct DateTime
{
		int year;
		int month;
		int day;
		int hour;
		int minute;
		int second;
}DateTime;
class Book
{
    protected:
        int bookNum;
        char bookName[30];
        char author[20];
        char bookConcern[30];
		char bookTime[30];
        int bookCount;
		int bookFlag;
    public:
        int getbookNum()
		{
			return bookNum;
		}
		void setBookNum(int booknum)
		{
			bookNum = booknum;
		}
		char *getbookName()
		{
			return bookName;
		}
		void setBookName(char bookname[])
		{
			strcpy(bookName,bookname);
		}
		char *getauthor()
		{
			return author;
		}
		void setauthor(char author1[])
		{
			strcpy(author,author1);
		}
		char *getbookConcern()
		{
			return bookConcern;
		}
		void setbookConcern(char bookconcern[])
		{
			strcpy(bookConcern,bookconcern);
		}
		char *getbookTime()
		{
			return bookTime;
		}
		void setbookTime(char booktime[])
		{
			strcpy(bookTime,booktime);
		}
		int getbookCount()
		{
			return bookCount;
		}
		void setbookCount(int bookcount)
		{
			bookCount = bookcount;
		}
		int getbookFlag()
		{
			return bookFlag;
		}
		void setbookFlag(int bookflag)
		{
			bookFlag = bookflag;
		}
		void addbook(int bnum, char *bname, char *auname, char *bcname, char *btime, int bcount) //����ͼ��
		{
			bookFlag = 0;
			bookNum = bnum;
			strcpy(bookName, bname);
			strcpy(author,auname);
			strcpy(bookConcern,bcname);
			strcpy(bookTime,btime);
			bookCount = bcount;
		}
		void display()//���ͼ��
		{
			cout<<bookNum<<"\t"<<bookName<<"\t"<<author<<"\t\t"<<bookConcern<<"\t\t"<<bookTime<<"\t"<<bookCount<<endl;
		}
		void deletebook() //����ɾ����� 1:��ɾ 0:δɾ
        {
            char i;
            cout<<"ȷ��ɾ����Y/N ?"<<endl;
            cin>>i;
            if(i=='y'||i=='Y')
                bookFlag = 1;
        }
		int borrowbook() //�������
		{ 
			if(bookCount > 0) 
			{
				return 1; 
			} 
			return 0; 
		} 
		void returnbook() //�������
		{
			bookCount++; 
		} 
};
class Book_lib
{
	protected:
		int top;
		Book book[Maxb];
	public:
		Book_lib() //���캯������book.txt����book[]��
		{
			Book b;
			top=-1;
			fstream file("book.txt",ios::in);
			while (1)
			{
				file.read((char *)&b,sizeof(b)); //�Զ������ļ��Ķ�ȡ����ڲ���Ϊchar,int���͡�
				if (!file)
					break;
				top++;
				book[top]=b;
			}
			file.close();
		}
		int gettop()
		{
			return top;
		}
		int addbook(int bnum, char *bname, char *auname, char *bcname, char *btime, int bcount)//����ͼ��
		{
		  Book *p = query1(bnum);
		  if (NULL == p)
		  {
			  top++;
			  book[top].addbook(bnum, bname, auname, bcname, btime, bcount);
			  return 1;
		  }
		  return 0;
		}
		Book *query1(int bnum) //����Ų���ͼ��
		{
			for(int i = 0; i <= top; i++)
				if(book[i].getbookNum() == bnum && book[i].getbookFlag() == 0)
				{
					return &book[i];
				}
			return NULL;
		}
		Book *query2(int bnum) //����Ų���ͼ��
		{
			Book *e;
			int r = 0;
			for(int i = 0; i <= top; i++)
			{
				if(book[i].getbookNum() == bnum && book[i].getbookFlag() == 0)
				{
					cout<<"���"<<"\t"<<"����"<<"\t"<<"����"<<"\t"<<"������"<<"\t\t"<<"����ʱ��"<<"\t"<<"����"<<endl;
					e = &book[i];
					e->display();
					r++;
				}
			}
			if(r==0)
				cout<<"�Ҳ�������!"<<endl;
			return NULL;
		}
		Book *query3(char bname[]) //����������ͼ��
		{
			Book *e;
			int r = 0;
			for(int i = 0; i <= top; i++)
			{
				if(strcmp(book[i].getbookName(),bname) == 0 && book[i].getbookFlag() == 0)
				{
					if(r == 0)
						cout<<"���"<<"\t"<<"����"<<"\t"<<"����"<<"\t"<<"������"<<"\t\t"<<"����ʱ��"<<"\t"<<"����"<<endl;
					e = &book[i];
					e->display();
					r++;
				}
			}
			if(r==0)
				cout<<"�Ҳ�������!"<<endl;
			return NULL;
		}
		Book *query4(char auname[]) //�����߲���ͼ��
		{
			Book *e;
			int r = 0;
			for(int i = 0; i <= top; i++)
			{
				if(strcmp(book[i].getauthor(),auname) == 0 && book[i].getbookFlag() == 0)
				{
					if(r == 0)
						cout<<"���"<<"\t"<<"����"<<"\t"<<"����"<<"\t"<<"������"<<"\t\t"<<"����ʱ��"<<"\t"<<"����"<<endl;
					e = &book[i];
					e->display();
					r = 1;
				}
			}
			if(r==0)
				cout<<"�Ҳ�������!"<<endl;
			return NULL;
		}
		Book *query5(char bcname[]) //�����������ͼ��
		{
			Book *e;
			int r = 0;
			for(int i = 0; i <= top; i++)
			{
				if(strcmp(book[i].getbookConcern(),bcname) == 0 && book[i].getbookFlag() == 0)
				{
					if(r == 0)
						cout<<"���"<<"\t"<<"����"<<"\t"<<"����"<<"\t"<<"������"<<"\t\t"<<"����ʱ��"<<"\t"<<"����"<<endl;
					e = &book[i];
					e->display();
					r++;
				}
			}
			if(r==0)
				cout<<"�Ҳ�������!"<<endl;
			return NULL;
		}
		void display()
		{
			for(int i = 0; i <= top; i++)
				if(book[i].getbookFlag() == 0)
					book[i].display();
		}
		void update(int bnum)
		{
			int r = 0;
			int t;
			for(int i = 0; i <= top; i++)
			{
				if(book[i].getbookNum() == bnum && book[i].getbookFlag() == 0)
				{
					do{
						cout<<"\n\t\t\t\t��ѡ����Ҫ�޸ĵ�ѡ�"<<endl;
						cout<<"\t\t\t\t1������"<<endl;
						cout<<"\t\t\t\t2������"<<endl;
						cout<<"\t\t\t\t3��������"<<endl;
						cout<<"\t\t\t\t4������ʱ��"<<endl;
						cout<<"\t\t\t\t5������"<<endl;
						cout<<"\t\t\t\t0������"<<endl;
						cin>>t;
					    system("cls");
						switch(t)
						{
							case 1:
								{
									char bname[30];
									cout<<"\t\t\t\t����������������"<<endl;
									cin>>bname;
									book[i].setBookName(bname);
									cout<<"\t\t\t\t�޸ĳɹ���"<<endl;
									system("pause");
							    	system("cls");
									break;
								}
							case 2:
								{
									char auname[20];
									cout<<"\t\t\t\t�����������������֣�"<<endl;
									cin>>auname;
									book[i].setauthor(auname);
									cout<<"\t\t\t\t�޸ĳɹ���"<<endl;
									system("pause");
									system("cls");
									break;
								}
							case 3:
								{
									char cbname[30];
									cout<<"\t\t\t\t������������������֣�"<<endl;
									cin>>cbname;
									book[i].setbookConcern(cbname);
									cout<<"\t\t\t\t�޸ĳɹ���"<<endl;
									system("pause");
									system("cls");
									break;
								}
							case 4:
								{
									char btime[30];
									cout<<"\t\t\t\t�������������ʱ�䣺"<<endl;
									cin>>btime;
									book[i].setbookTime(btime);
									cout<<"\t\t\t\t�޸ĳɹ���"<<endl;
									system("pause");
									system("cls");
									break;
								}
							case 5:
								{
									int count1;
									cout<<"\t\t\t\t���������������"<<endl;
									cin>>count1;
									book[i].setbookCount(count1);
									cout<<"\t\t\t\t�޸ĳɹ���"<<endl;
									system("pause");
									system("cls");
									break;
								}
							case 0:
								break;
							default:
								cout<<"�����������������룡"<<endl;
								system("pause");
								system("cls");
			               	    break;
						}
					}while(t != 0);
					r = 1;
				}
			}
			if(r == 0)
				cout<<"\t\t\t\t�Ҳ�������!"<<endl;
		}
		void borrow_book(int bnum)
		{
			int r = 0;
			for(int i = 0; i <= top; i++)
			{
				if(book[i].getbookNum() == bnum && book[i].getbookFlag() == 0)
				{
			
					int count1 = book[i].getbookCount();
					count1 = --count1;
					book[i].setbookCount(count1);
					r = 1;
				}
			}
			if(r == 0)
				cout<<"\t\t\t\t�Ҳ�������!"<<endl;
		}
		void return_book(int bnum)
		{
			int r = 0;
			for(int i = 0; i <= top; i++)
			{
				if(book[i].getbookNum() == bnum && book[i].getbookFlag() == 0)
				{
			
					int count1 = book[i].getbookCount();
					count1 = ++count1;
					book[i].setbookCount(count1);
					r = 1;
				}
			}
			if(r == 0)
				cout<<"\t\t\t\t�Ҳ�������!"<<endl;
		}
		void clear() //ɾ������ͼ����Ϣ
        {
            char i;
            cout<<"\t\t\t\tȷ��ȫ��ɾ����Y/N ?"<<endl;
            cin>>i;
            if(i=='y'||i=='Y')
                top=-1;
        }
		void InterFace()
		{
			int n;
			int bnum;
			int bcount;
			Book *b;
			char bname[30];
			char auname[20];
			char bcname[30];
			char btime[30];
			do{
				cout<<"\n\t\t\t\tͼ�����"<<endl;
				cout<<"\t\t\t\t1��ͼ�����"<<endl;
				cout<<"\t\t\t\t2��ͼ��鿴"<<endl;
				cout<<"\t\t\t\t3��ͼ����Ϣ�޸�"<<endl;
				cout<<"\t\t\t\t4��ͼ��ɾ��"<<endl;
				cout<<"\t\t\t\t0������"<<endl;
				cin>>n;
				system("cls");
				switch(n)
				{
					case 1:
						{
							cout<<"\t\t\t\t�����������ţ�";
							cin>>bnum;
							b = query1(bnum);
							if(b != NULL)
							{
								cout<<"\t\t\t\t�ñ���Ѿ����ڣ��������!"<<endl;
								system("pause");
					            system("cls");
								break;
							}
							cout<<"\t\t\t\t����������������";
							cin>>bname;
							cout<<"\t\t\t\t������������������";
							cin>>auname;
							cout<<"\t\t\t\t��������������磺";
							cin>>bcname;
							cout<<"\t\t\t\t�������������ʱ�䣺";
							cin>>btime;
							cout<<"\t\t\t\t����������������";
							cin>>bcount;
							addbook(bnum, bname, auname, bcname, btime, bcount);
							cout<<"\t\t\t\t��ӳɹ���"<<endl;
							system("pause");
					        system("cls");
							break;
						}
					case 2:
						{
							int t;
							do{
								cout<<"\t\t\t\t1������ͼ���Ų鿴"<<endl;
								cout<<"\t\t\t\t2������ͼ�����ֲ鿴"<<endl;
								cout<<"\t\t\t\t3������ͼ�����߲鿴"<<endl;
								cout<<"\t\t\t\t4�����ݳ�����鿴"<<endl;
								cout<<"\t\t\t\t5���鿴ȫ�����ͼ��"<<endl;
								cout<<"\t\t\t\t0������"<<endl;
								cin>>t;
								system("cls");
								switch(t)
								{
									case 1:
										{
											cout<<"\t\t\t\t��������ı�ţ�";
											cin>>bnum;
											query2(bnum);
											system("pause");
											system("cls");
											break;
										}
									case 2:
										{
											char bname[30];
											cout<<"\t\t\t\t�����������֣�"<<endl;
											cin>>bname;
											query3(bname);
											system("pause");
											system("cls");
											break;
										}
									case 3:
										{
											cout<<"\t\t\t\t�������������֣�"<<endl;
											cin>>auname;
											query4(auname);
											system("pause");
											system("cls");
											break;
										}
									case 4:
										{
											cout<<"\t\t\t\t��������������֣�"<<endl;
											cin>>bcname;
											query5(bcname);
											system("pause");
											system("cls");
											break;
										}
									case 5:
										{
											cout<<"���"<<"\t"<<"����"<<"\t"<<"����"<<"\t\t"<<"������"<<"\t\t"<<"����ʱ��"<<"\t"<<"����"<<endl;
											display();
											system("pause");
											system("cls");
											break;
										}
									case 0:
										break;
									default:
										cout<<"�����������������룡"<<endl;
										system("pause");
					                    system("cls");
			                    	    break;
								}
							}while(t != 0);
					        system("cls");
							break;
						}
					case 3:
						{
							cout<<"\t\t\t\t��������Ҫ�޸�ͼ��ı�ţ�"<<endl;
							cin>>bnum;
							system("cls");
							update(bnum);
							system("pause");
					        system("cls");
							break;
						}
					case 4:
					{
					    int t;
					    do{
					        cout<<"\n\t\t\t\t1������ɾ��"<<endl;
					        cout<<"\t\t\t\t2��ȫ��ɾ��"<<endl;
					        cout<<"\t\t\t\t0������"<<endl;
					        cin>>t;
					        system("cls");
					        switch(t)
					        {
					            case 1:
					            {
					                int bnum;
					                Book *b;
                                    cout<<"\t\t\t\t\t������Ҫɾ��ͼ��ı�ţ�"<<endl;
                                    cin>>bnum;
                                    b = query1(bnum);
                                    if(b == NULL)
                                    {
                                        cout<<"\t\t\t\t��ͼ�鲻���ڣ��޷�ɾ��!"<<endl;
										system("pause");
					                    system("cls");
                                        break;
                                    }
                                    b->deletebook();
                                    cout<<"\t\t\t\tɾ���ɹ�!"<<endl;
									system("pause");
					                system("cls");
									break;
					            }
					            case 2:
					            {
					                clear();
					                cout<<"\t\t\t\t����գ�"<<endl;
									system("pause");
					                system("cls");
					                break;
					            }
					            case 0:
                                    break;
								default:
									cout<<"�����������������룡"<<endl;
									system("pause");
									system("cls");
			                        break;
					        }
					    }while(t != 0);
						break;
					}
					case 0:
						break;
					default:
						cout<<"�����������������룡"<<endl;
						system("pause");
					    system("cls");
			       	    break;
				}
			}while(n != 0);
		}
		~Book_lib() //������������book[]д��book.txt�ļ���
		{
			fstream file("book.txt",ios::out);
			for(int i = 0; i <= top; i++)
				if(book[i].getbookFlag() == 0)
					file.write((char *)&book[i],sizeof(book[i]));
			file.close();
		}
};
class Reader
{
    protected:
        int readerNum;
        char readerName[20];
        int age;
        char sex[3];
		int flag;
    public:
		int borrow_booknum[Maxbor];
		DateTime borrow_time[Maxbor];
		int getreaderNum()
		{
			return readerNum;
		}
		void setreaderNum(int readernum)
		{
			readerNum = readernum;
		}
		char *getreaderName()
		{
			return readerName;
		}
		void setreaderName(char readername[])
		{
			strcpy(readerName,readername);
		}
		int getage()
		{
			return age;
		}
		void setage(int age1)
		{
			age = age1;
		}
		char *getsex()
		{
			return sex;
		}
		void setsex(char sex1[])
		{
			strcpy(sex,sex1);
		}
		int getflag()
		{
			return 0;
		}
		void setflag(int flag1)
		{
			flag = flag1;
		}
		void addreader(int rnum, char rname[], int age1, char sex1[])
		{
			flag = 0;
			readerNum = rnum;
			strcpy(readerName, rname);
			age = age1;
			strcpy(sex,sex1);
			for(int i = 0; i < Maxbor; i++) 
				borrow_booknum[i] = 0;
		}
		void borrowbook(int bbnum) //�������
		{ 
			for(int i = 0; i < Maxbor; i++) 
			{ 
				if (borrow_booknum[i] == 0) 
				{
					long now = time(NULL);
					tm local = *localtime(& now);
					borrow_time[i].year = local.tm_year+1900;
					borrow_time[i].month = local.tm_mon+1;
					borrow_time[i].day = local.tm_mday;
					borrow_time[i].hour = local.tm_hour;
					borrow_time[i].minute = local.tm_min;
					borrow_time[i].second = local.tm_sec;
					borrow_booknum[i] = bbnum;
					return ; 
				} 
			} 
		}
		int returnbook(int rbnum) //������� 
		{
			for(int i = 0; i < Maxbor; i++) 
			{
				if(borrow_booknum[i] == rbnum) 
				{ 
					borrow_booknum[i] = 0;
					cout<<"\t\t\t\t����ɹ�!"<<endl;
					return 1; 
				} 
			}
			cout<<"\t\t\t\tδ����飬����ʧ��!"<<endl;
			return 0; 
		} 
		void deleteperson() //����ɾ����� 1:��ɾ 0:δɾ
        {
            char i;
            cout<<"\t\t\t\tȷ��ɾ����Y/N ?"<<endl;
            cin>>i;
            if(i=='y'||i=='Y')
                flag = 1;
        }
		void display()
		{
			int have = 0;
			int flag1 = 0;
			cout<<readerNum<<"\t"<<readerName<<"\t"<<age<<"\t"<<sex<<"\t\t";
			for(int i = 0; i < Maxbor; i++) 
				if(borrow_booknum[i]!=0)
				{ 
					if(flag1 == 0)
					{
						have = 1;
						cout<<borrow_booknum[i]<<"\t\t";
						cout<<borrow_time[i].year<<"-"<<setfill('0')<<setw(2)<<borrow_time[i].month
							<<"-"<<setfill('0')<<setw(2)<<borrow_time[i].day<<" "<<setfill('0')
							<<setw(2)<<borrow_time[i].hour<<":"<<setfill('0')<<setw(2)<<borrow_time[i].minute
							<<":"<<setfill('0')<<setw(2)<<borrow_time[i].second<<endl;
						flag1++;
					}
					else
					{
						cout<<"\t\t\t\t\t"<<borrow_booknum[i]<<"\t\t"; 
						cout<<borrow_time[i].year<<"-"<<setfill('0')<<setw(2)<<borrow_time[i].month
							<<"-"<<setfill('0')<<setw(2)<<borrow_time[i].day<<" "<<setfill('0')
							<<setw(2)<<borrow_time[i].hour<<":"<<setfill('0')<<setw(2)<<borrow_time[i].minute
							<<":"<<setfill('0')<<setw(2)<<borrow_time[i].second<<endl;
					}
				}
			if(have == 0)
				cout<<"��"<<endl;
		}

};
class Reader_lib
{
	protected:
		int top;
		Reader reader[Maxr];
	public:
		Reader_lib() //���캯������reader.txt����read[]��
		{ 
			Reader r; 
			top = -1;  
			fstream file("reader.txt",ios::in); //��һ�������ļ�
			while (1) 
			{ 
				file.read((char *)&r,sizeof(r)); 
				if (!file)
					break; 
				top++; 
				reader[top]=r; 
			} 
			file.close(); //�ر� reader.txt �ļ�
		} 
		Reader *queryid(int readerid) //�����߱�Ų���
		{
			for (int i = 0; i <= top; i++) 
				if (reader[i].getreaderNum() == readerid && reader[i].getflag() == 0) 
				{ 
					return &reader[i]; 
				} 
			return NULL;
		}                       
		void display() //������ж�����Ϣ 
		{
			for(int i = 0;i <= top; i++)
				if(reader[i].getflag() == 0)
					reader[i].display();
		} 
		int addreader(int rnum, char rname[], int age1, char sex1[])//���Ӷ���
		{
			Reader *r = queryid(rnum);
			if (NULL == r)
			{
				top++;
				reader[top].addreader(rnum,rname,age1,sex1);
			}
			return 0;
		}
		void updateReader(int rnum)
		{
			char rname[30];
			char sex1[3];
			int age1;
			int t;
			for(int i = 0; i <= top; i++)
			{
				if(reader[i].getreaderNum() == rnum && reader[i].getflag() == 0)
				{
					do
					{
						cout<<"\n\t\t\t\t��ѡ��Ҫ�޸ĵĻ�����Ϣ"<<endl;
						cout<<"\t\t\t\t1������"<<endl;
						cout<<"\t\t\t\t2������"<<endl;
						cout<<"\t\t\t\t3���Ա�"<<endl;
						cout<<"\t\t\t\t0������"<<endl;
						cin>>t;
					    system("cls");
						switch(t)
						{
							case 1:
								{
									cout<<"\t\t\t\t����������������"<<endl;
									cin>>rname;
									reader[i].setreaderName(rname);
									system("pause");
					                system("cls");
									break;
								}
							case 2:
								{
									do{
										cout<<"\t\t\t\t����������������䣺";
										cin>>age1;
										if(age1 < 0 || age1 >150)
											cout<<"\t\t\t\t��������"<<endl;
									}while(age1 >= 0 || age1 <=150);
									reader[i].setage(age1);
									system("pause");
					                system("cls");
									break;
								}
							case 3:
								{
									do{
											cout<<"\t\t\t\t��������������Ա�";
											cin>>sex1;
											if(strcmp(sex1,"f") != 0 || strcmp(sex1,"m") != 0)
												cout<<"\t\t\t\t��������"<<endl;
										}while(strcmp(sex1,"f") == 0 || strcmp(sex1,"m") == 0);
										reader[i].setsex(sex1);
										system("pause");
					                    system("cls");
										break;
								}
							case 0:
								break;
							default:
								cout<<"�����������������룡"<<endl;
								system("pause");
								system("cls");
			                    break;
						}
					}while(t != 0);
				}
			}
		}
		void borrow_book(int rnum, Book b)
		{
			for(int i = 0; i <= top; i++)
			{
				if(reader[i].getreaderNum() == rnum && reader[i].getflag() == 0)
				{
					reader[i].borrowbook(b.getbookNum());
				}
			}
		}
		void return_book(int rnum, Book b)
		{
			for(int i = 0; i <= top; i++)
			{
				if(reader[i].getreaderNum() == rnum && reader[i].getflag() == 0)
				{
					reader[i].returnbook(b.getbookNum());
				}
			}
		}
		void delete_all()
		{
			char i;
            cout<<"\t\t\t\tȷ��ȫ��ɾ����Y/N ?"<<endl;
            cin>>i;
            if(i=='y'||i=='Y')
                top=-1;
		}
		void delete_person()
		{
			int rnum;
			Reader *r;
            cout<<"\t\t\t\t������Ҫɾ�����ߵı�ţ�"<<endl;
            cin>>rnum;
            r = queryid(rnum);
            if(r == NULL)
            {
                cout<<"\t\t\t\t�ñ�Ų����ڣ��޷�ɾ��!"<<endl;
                return ;
            }
            r->deleteperson();
            cout<<"\t\t\t\tɾ���ɹ�!"<<endl;
			return ;
		}
		void InterFace()
		{
			int n;
			char rname[30];
			char sex1[3];
			int rnum;
			int age1;
			Reader *r;
			do{
				cout<<"\n\n\t\t\t\t���߹���\n"<<endl;
				cout<<"\t\t\t\t1���������"<<endl;
				cout<<"\t\t\t\t2��������Ϣ�鿴"<<endl;
				cout<<"\t\t\t\t3��������Ϣ�޸�"<<endl;
				cout<<"\t\t\t\t4������ɾ��"<<endl;
				cout<<"\t\t\t\t0������"<<endl;
				cin>>n;
				system("cls");
				switch(n)
				{
					case 1:
						{
							cout<<"\n\t\t\t\t�������¶��ߵı�ţ�";
							cin>>rnum;
							r = queryid(rnum);
							if(r != NULL)
							{
								cout<<"\n\t\t\t\t�ñ���Ѿ����ڣ��������!"<<endl;
								system("pause");
								system("cls");
								break;
							}
							cout<<"\t\t\t\t���������������";
							cin>>rname;
							do{
								cout<<"\t\t\t\t������������䣺";
								cin>>age1;
								if(age1 < 0 || age1 >150)
									cout<<"\t\t\t\t��������"<<endl;
							}while(age1 < 0 || age1 >150);
							do{
								cout<<"\t\t\t\t����������Ա�";
								cin>>sex1;
								if(strcmp(sex1,"man") == 1 || strcmp(sex1,"woman") == 1)
									cout<<"\t\t\t\t��������"<<endl;
							}while(strcmp(sex1,"man") == 1 || strcmp(sex1,"woman") == 1);
							addreader(rnum,rname,age1,sex1);
							cout<<"\t\t\t\t��ӳɹ���"<<endl;
							system("pause");
				         	system("cls");
							break;
						}
					case 2:
						{
							cout<<"���"<<"\t"<<"����"<<"\t"<<"����"<<"\t"<<"�Ա�"<<"\t\t"<<"�ѽ��鼮���"<<"\t"<<"����ʱ��"<<endl;
							display();
							system("pause");
				         	system("cls");
							break;
						}
					case 3:
						{
							cout<<"\n\t\t\t\t��������߱�ţ�"; 
							cin>>rnum; 
							r = queryid(rnum); 
							if(r == NULL) 
							{ 
								cout<<"\t\t\t\t�ö��߲�����! "<<endl;
								system("pause");
								system("cls");
								break;
							} 
							updateReader(rnum);
							cout<<"\t\t\t\t�޸Ķ��߳ɹ�!"<<endl;
							system("pause");
				         	system("cls");
							break;
						}
					case 4:
						{
							int t;
							do{
								cout<<"\n\t\t\t\t��ѡ��ɾ��ȫ��/���ˣ�"<<endl;
								cout<<"\t\t\t\t1��ȫ��"<<endl;
								cout<<"\t\t\t\t2������"<<endl;
								cout<<"\t\t\t\t0������"<<endl;
								cin>>t;
					            system("cls");
								switch(t)
								{
									case 1:
										{
											delete_all();
											system("pause");
					                        system("cls");
											break;
										}
									case 2:
										{
											delete_person();
											system("pause");
				                        	system("cls");
											break;
										}
									case 0:
										break;
									default:
										cout<<"\t\t\t\t�����������������룡"<<endl;
										system("pause");
										system("cls");
			                    	    break;
								}
							}while(t != 0);
							break;
						}
					case 0:
						break;
					default:
						cout<<"\t\t\t\t�����������������룡"<<endl;
						system("pause");
					    system("cls");
			            break;
				}
			}while(n != 0);
		}
		~Reader_lib() //������������read[]д��reader.txt�ļ���
			{
			   fstream file("reader.txt",ios::out); 
			   for(int i = 0; i <= top; i++) 
				   if (reader[i].getflag() == 0) 
					  file.write((char *)&reader[i],sizeof(reader[i])); 
			   file.close(); 
			} 
};
class Main_interface
{
    public:
        void display();
};
void Main_interface::display()
{
    int n;
	Book *b;
	Reader *r;
	Book_lib bl;
	Reader_lib rl;
    do{
        cout<<"\n\n\t\t\t\tͼ��ݹ���ϵͳ\n"<<endl;
        cout<<"\t\t\t\t1��ͼ�����"<<endl;
        cout<<"\t\t\t\t2�����߹���"<<endl;
		cout<<"\t\t\t\t3������"<<endl;
		cout<<"\t\t\t\t4������"<<endl;
        cout<<"\t\t\t\t0���˳�"<<endl;
        cout<<"\t\t\t\t��ѡ��";
        cin>>n;
		system("cls");
        switch(n)
        {
            case 1:
				{
					bl.InterFace();
					system("pause");
					system("cls");
					break;
				}
            case 2:
				{
					rl.InterFace();
					system("pause");
					system("cls");
					break;
				}
			case 3:
				{
					int rnum;
					cout<<"\n\t\t\t\t��������߱�ţ�"; 
					cin>>rnum; 
					r = rl.queryid(rnum); 
					if(r == NULL) 
					{ 
						cout<<"\t\t\t\t�ö��߲�����, ��ע�ᣡ "<<endl;
						system("pause");
					    system("cls");
						break;
					} 
					int bnum;
					cout<<"\t\t\t\t���������ͼ���ţ�";
					cin>>bnum;
					b = bl.query1(bnum);
					if(b == NULL)
					{
						cout<<"\t\t\t\t����ͼ�飡"<<endl;
						system("pause");
					    system("cls");
						break;
					}
					if(b->borrowbook() == 0) 
					{ 
						cout<<"\t\t\t\t��ͼ���ѽ��꣬���ܽ���!"<<endl;
						system("pause");
					    system("cls");
						break; 
					}
					rl.borrow_book(rnum, *b);
					bl.borrow_book(bnum);
					cout<<"\t\t\t\t����ɹ���"<<endl;
					system("pause");
					system("cls");
					break;
				}
			case 4:
				{
					int rnum;
					cout<<"\t\t\t\t��������߱�ţ�"; 
					cin>>rnum; 
					r = rl.queryid(rnum); 
					if(r == NULL) 
					{ 
						cout<<"\t\t\t\t�ö��߲�����, ��ע�ᣡ "<<endl;
						system("pause");
					    system("cls");
						break;
					} 
					int bnum;
					cout<<"\t\t\t\t������Ҫ�黹ͼ����:"; 
					cin>>bnum; 
					b = bl.query1(bnum); 
					if(b == NULL) 
					{
						 cout<<"\t\t\t\t�����ڸ�ͼ�飬���ܻ���"<<endl; 
						 system("pause");
					     system("cls");
						 break; 
					}
					rl.return_book(rnum, *b);
					bl.return_book(bnum);
					system("pause");
					system("cls");
					break;
				}
            case 0:
				{
					cout<<"ллʹ�ã�"<<endl;
					system("pause");
					break;
				}
			default:
				cout<<"�����������������룡"<<endl;
				system("pause");
				system("cls");
			    break; 
        }
    }while(n != 0);
}
int main()
{
    Main_interface mi;
    mi.display();
    return 0;
}
