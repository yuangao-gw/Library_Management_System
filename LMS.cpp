#include<bits/stdc++.h>
using namespace std;

const int Maxr = 100;//最多的读者数
const int Maxb = 100; //最多的图书数
const int Maxbor = 5; //每位读者最多借的书
const int MaxDate = 1000; //日志记录上线

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
		void addbook(int bnum, char *bname, char *auname, char *bcname, char *btime, int bcount) //增加图书
		{
			bookFlag = 0;
			bookNum = bnum;
			strcpy(bookName, bname);
			strcpy(author,auname);
			strcpy(bookConcern,bcname);
			strcpy(bookTime,btime);
			bookCount = bcount;
		}
		void display()//输出图书
		{
			cout<<bookNum<<"\t"<<bookName<<"\t"<<author<<"\t\t"<<bookConcern<<"\t\t"<<bookTime<<"\t"<<bookCount<<endl;
		}
		void deletebook() //设置删除标记 1:已删 0:未删
        {
            char i;
            cout<<"确定删除吗？Y/N ?"<<endl;
            cin>>i;
            if(i=='y'||i=='Y')
                bookFlag = 1;
        }
		int borrowbook() //借书操作
		{ 
			if(bookCount > 0) 
			{
				return 1; 
			} 
			return 0; 
		} 
		void returnbook() //还书操作
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
		Book_lib() //构造函数，将book.txt读到book[]中
		{
			Book b;
			top=-1;
			fstream file("book.txt",ios::in);
			while (1)
			{
				file.read((char *)&b,sizeof(b)); //对二进制文件的读取，入口参数为char,int类型。
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
		int addbook(int bnum, char *bname, char *auname, char *bcname, char *btime, int bcount)//增加图书
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
		Book *query1(int bnum) //按编号查找图书
		{
			for(int i = 0; i <= top; i++)
				if(book[i].getbookNum() == bnum && book[i].getbookFlag() == 0)
				{
					return &book[i];
				}
			return NULL;
		}
		Book *query2(int bnum) //按编号查找图书
		{
			Book *e;
			int r = 0;
			for(int i = 0; i <= top; i++)
			{
				if(book[i].getbookNum() == bnum && book[i].getbookFlag() == 0)
				{
					cout<<"编号"<<"\t"<<"书名"<<"\t"<<"作者"<<"\t"<<"出版社"<<"\t\t"<<"出版时间"<<"\t"<<"存量"<<endl;
					e = &book[i];
					e->display();
					r++;
				}
			}
			if(r==0)
				cout<<"找不到该书!"<<endl;
			return NULL;
		}
		Book *query3(char bname[]) //按书名查找图书
		{
			Book *e;
			int r = 0;
			for(int i = 0; i <= top; i++)
			{
				if(strcmp(book[i].getbookName(),bname) == 0 && book[i].getbookFlag() == 0)
				{
					if(r == 0)
						cout<<"编号"<<"\t"<<"书名"<<"\t"<<"作者"<<"\t"<<"出版社"<<"\t\t"<<"出版时间"<<"\t"<<"存量"<<endl;
					e = &book[i];
					e->display();
					r++;
				}
			}
			if(r==0)
				cout<<"找不到该书!"<<endl;
			return NULL;
		}
		Book *query4(char auname[]) //按作者查找图书
		{
			Book *e;
			int r = 0;
			for(int i = 0; i <= top; i++)
			{
				if(strcmp(book[i].getauthor(),auname) == 0 && book[i].getbookFlag() == 0)
				{
					if(r == 0)
						cout<<"编号"<<"\t"<<"书名"<<"\t"<<"作者"<<"\t"<<"出版社"<<"\t\t"<<"出版时间"<<"\t"<<"存量"<<endl;
					e = &book[i];
					e->display();
					r = 1;
				}
			}
			if(r==0)
				cout<<"找不到该书!"<<endl;
			return NULL;
		}
		Book *query5(char bcname[]) //按出版社查找图书
		{
			Book *e;
			int r = 0;
			for(int i = 0; i <= top; i++)
			{
				if(strcmp(book[i].getbookConcern(),bcname) == 0 && book[i].getbookFlag() == 0)
				{
					if(r == 0)
						cout<<"编号"<<"\t"<<"书名"<<"\t"<<"作者"<<"\t"<<"出版社"<<"\t\t"<<"出版时间"<<"\t"<<"存量"<<endl;
					e = &book[i];
					e->display();
					r++;
				}
			}
			if(r==0)
				cout<<"找不到该书!"<<endl;
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
						cout<<"\n\t\t\t\t请选择您要修改的选项："<<endl;
						cout<<"\t\t\t\t1、书名"<<endl;
						cout<<"\t\t\t\t2、作者"<<endl;
						cout<<"\t\t\t\t3、出版社"<<endl;
						cout<<"\t\t\t\t4、出版时间"<<endl;
						cout<<"\t\t\t\t5、存量"<<endl;
						cout<<"\t\t\t\t0、返回"<<endl;
						cin>>t;
					    system("cls");
						switch(t)
						{
							case 1:
								{
									char bname[30];
									cout<<"\t\t\t\t请重新输入书名："<<endl;
									cin>>bname;
									book[i].setBookName(bname);
									cout<<"\t\t\t\t修改成功！"<<endl;
									system("pause");
							    	system("cls");
									break;
								}
							case 2:
								{
									char auname[20];
									cout<<"\t\t\t\t请重新输入作者名字："<<endl;
									cin>>auname;
									book[i].setauthor(auname);
									cout<<"\t\t\t\t修改成功！"<<endl;
									system("pause");
									system("cls");
									break;
								}
							case 3:
								{
									char cbname[30];
									cout<<"\t\t\t\t请重新输入出版社名字："<<endl;
									cin>>cbname;
									book[i].setbookConcern(cbname);
									cout<<"\t\t\t\t修改成功！"<<endl;
									system("pause");
									system("cls");
									break;
								}
							case 4:
								{
									char btime[30];
									cout<<"\t\t\t\t请重新输入出版时间："<<endl;
									cin>>btime;
									book[i].setbookTime(btime);
									cout<<"\t\t\t\t修改成功！"<<endl;
									system("pause");
									system("cls");
									break;
								}
							case 5:
								{
									int count1;
									cout<<"\t\t\t\t请重新输入存量："<<endl;
									cin>>count1;
									book[i].setbookCount(count1);
									cout<<"\t\t\t\t修改成功！"<<endl;
									system("pause");
									system("cls");
									break;
								}
							case 0:
								break;
							default:
								cout<<"输入有误，请重新输入！"<<endl;
								system("pause");
								system("cls");
			               	    break;
						}
					}while(t != 0);
					r = 1;
				}
			}
			if(r == 0)
				cout<<"\t\t\t\t找不到该书!"<<endl;
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
				cout<<"\t\t\t\t找不到该书!"<<endl;
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
				cout<<"\t\t\t\t找不到该书!"<<endl;
		}
		void clear() //删除所有图书信息
        {
            char i;
            cout<<"\t\t\t\t确定全部删除吗？Y/N ?"<<endl;
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
				cout<<"\n\t\t\t\t图书管理"<<endl;
				cout<<"\t\t\t\t1、图书添加"<<endl;
				cout<<"\t\t\t\t2、图书查看"<<endl;
				cout<<"\t\t\t\t3、图书信息修改"<<endl;
				cout<<"\t\t\t\t4、图书删除"<<endl;
				cout<<"\t\t\t\t0、返回"<<endl;
				cin>>n;
				system("cls");
				switch(n)
				{
					case 1:
						{
							cout<<"\t\t\t\t请输入新书编号：";
							cin>>bnum;
							b = query1(bnum);
							if(b != NULL)
							{
								cout<<"\t\t\t\t该编号已经存在，不能添加!"<<endl;
								system("pause");
					            system("cls");
								break;
							}
							cout<<"\t\t\t\t请输入新书书名：";
							cin>>bname;
							cout<<"\t\t\t\t请输入新书作者名：";
							cin>>auname;
							cout<<"\t\t\t\t请输入新书出版社：";
							cin>>bcname;
							cout<<"\t\t\t\t请输入新书出版时间：";
							cin>>btime;
							cout<<"\t\t\t\t请输入新书数量：";
							cin>>bcount;
							addbook(bnum, bname, auname, bcname, btime, bcount);
							cout<<"\t\t\t\t添加成功！"<<endl;
							system("pause");
					        system("cls");
							break;
						}
					case 2:
						{
							int t;
							do{
								cout<<"\t\t\t\t1、根据图书编号查看"<<endl;
								cout<<"\t\t\t\t2、根据图书名字查看"<<endl;
								cout<<"\t\t\t\t3、根据图书作者查看"<<endl;
								cout<<"\t\t\t\t4、根据出版社查看"<<endl;
								cout<<"\t\t\t\t5、查看全部库存图书"<<endl;
								cout<<"\t\t\t\t0、返回"<<endl;
								cin>>t;
								system("cls");
								switch(t)
								{
									case 1:
										{
											cout<<"\t\t\t\t请输入书的编号：";
											cin>>bnum;
											query2(bnum);
											system("pause");
											system("cls");
											break;
										}
									case 2:
										{
											char bname[30];
											cout<<"\t\t\t\t请输入书名字："<<endl;
											cin>>bname;
											query3(bname);
											system("pause");
											system("cls");
											break;
										}
									case 3:
										{
											cout<<"\t\t\t\t请输入作者名字："<<endl;
											cin>>auname;
											query4(auname);
											system("pause");
											system("cls");
											break;
										}
									case 4:
										{
											cout<<"\t\t\t\t请输入出版社名字："<<endl;
											cin>>bcname;
											query5(bcname);
											system("pause");
											system("cls");
											break;
										}
									case 5:
										{
											cout<<"编号"<<"\t"<<"书名"<<"\t"<<"作者"<<"\t\t"<<"出版社"<<"\t\t"<<"出版时间"<<"\t"<<"存量"<<endl;
											display();
											system("pause");
											system("cls");
											break;
										}
									case 0:
										break;
									default:
										cout<<"输入有误，请重新输入！"<<endl;
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
							cout<<"\t\t\t\t请输入您要修改图书的编号："<<endl;
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
					        cout<<"\n\t\t\t\t1、个别删除"<<endl;
					        cout<<"\t\t\t\t2、全部删除"<<endl;
					        cout<<"\t\t\t\t0、返回"<<endl;
					        cin>>t;
					        system("cls");
					        switch(t)
					        {
					            case 1:
					            {
					                int bnum;
					                Book *b;
                                    cout<<"\t\t\t\t\t请输入要删除图书的编号："<<endl;
                                    cin>>bnum;
                                    b = query1(bnum);
                                    if(b == NULL)
                                    {
                                        cout<<"\t\t\t\t该图书不存在，无法删除!"<<endl;
										system("pause");
					                    system("cls");
                                        break;
                                    }
                                    b->deletebook();
                                    cout<<"\t\t\t\t删除成功!"<<endl;
									system("pause");
					                system("cls");
									break;
					            }
					            case 2:
					            {
					                clear();
					                cout<<"\t\t\t\t已清空！"<<endl;
									system("pause");
					                system("cls");
					                break;
					            }
					            case 0:
                                    break;
								default:
									cout<<"输入有误，请重新输入！"<<endl;
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
						cout<<"输入有误，请重新输入！"<<endl;
						system("pause");
					    system("cls");
			       	    break;
				}
			}while(n != 0);
		}
		~Book_lib() //析构函数，将book[]写到book.txt文件中
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
		void borrowbook(int bbnum) //借书操作
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
		int returnbook(int rbnum) //还书操作 
		{
			for(int i = 0; i < Maxbor; i++) 
			{
				if(borrow_booknum[i] == rbnum) 
				{ 
					borrow_booknum[i] = 0;
					cout<<"\t\t\t\t还书成功!"<<endl;
					return 1; 
				} 
			}
			cout<<"\t\t\t\t未借该书，还书失败!"<<endl;
			return 0; 
		} 
		void deleteperson() //设置删除标记 1:已删 0:未删
        {
            char i;
            cout<<"\t\t\t\t确定删除吗？Y/N ?"<<endl;
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
				cout<<"无"<<endl;
		}

};
class Reader_lib
{
	protected:
		int top;
		Reader reader[Maxr];
	public:
		Reader_lib() //构造函数，将reader.txt读到read[]中
		{ 
			Reader r; 
			top = -1;  
			fstream file("reader.txt",ios::in); //打开一个输入文件
			while (1) 
			{ 
				file.read((char *)&r,sizeof(r)); 
				if (!file)
					break; 
				top++; 
				reader[top]=r; 
			} 
			file.close(); //关闭 reader.txt 文件
		} 
		Reader *queryid(int readerid) //按读者编号查找
		{
			for (int i = 0; i <= top; i++) 
				if (reader[i].getreaderNum() == readerid && reader[i].getflag() == 0) 
				{ 
					return &reader[i]; 
				} 
			return NULL;
		}                       
		void display() //输出所有读者信息 
		{
			for(int i = 0;i <= top; i++)
				if(reader[i].getflag() == 0)
					reader[i].display();
		} 
		int addreader(int rnum, char rname[], int age1, char sex1[])//增加读者
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
						cout<<"\n\t\t\t\t请选择要修改的基本信息"<<endl;
						cout<<"\t\t\t\t1、姓名"<<endl;
						cout<<"\t\t\t\t2、年龄"<<endl;
						cout<<"\t\t\t\t3、性别"<<endl;
						cout<<"\t\t\t\t0、返回"<<endl;
						cin>>t;
					    system("cls");
						switch(t)
						{
							case 1:
								{
									cout<<"\t\t\t\t请重新输入姓名："<<endl;
									cin>>rname;
									reader[i].setreaderName(rname);
									system("pause");
					                system("cls");
									break;
								}
							case 2:
								{
									do{
										cout<<"\t\t\t\t请重新输入读者年龄：";
										cin>>age1;
										if(age1 < 0 || age1 >150)
											cout<<"\t\t\t\t输入有误！"<<endl;
									}while(age1 >= 0 || age1 <=150);
									reader[i].setage(age1);
									system("pause");
					                system("cls");
									break;
								}
							case 3:
								{
									do{
											cout<<"\t\t\t\t请重新输入读者性别：";
											cin>>sex1;
											if(strcmp(sex1,"f") != 0 || strcmp(sex1,"m") != 0)
												cout<<"\t\t\t\t输入有误！"<<endl;
										}while(strcmp(sex1,"f") == 0 || strcmp(sex1,"m") == 0);
										reader[i].setsex(sex1);
										system("pause");
					                    system("cls");
										break;
								}
							case 0:
								break;
							default:
								cout<<"输入有误，请重新输入！"<<endl;
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
            cout<<"\t\t\t\t确定全部删除吗？Y/N ?"<<endl;
            cin>>i;
            if(i=='y'||i=='Y')
                top=-1;
		}
		void delete_person()
		{
			int rnum;
			Reader *r;
            cout<<"\t\t\t\t请输入要删除读者的编号："<<endl;
            cin>>rnum;
            r = queryid(rnum);
            if(r == NULL)
            {
                cout<<"\t\t\t\t该编号不存在，无法删除!"<<endl;
                return ;
            }
            r->deleteperson();
            cout<<"\t\t\t\t删除成功!"<<endl;
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
				cout<<"\n\n\t\t\t\t读者管理\n"<<endl;
				cout<<"\t\t\t\t1、读者添加"<<endl;
				cout<<"\t\t\t\t2、读者信息查看"<<endl;
				cout<<"\t\t\t\t3、读者信息修改"<<endl;
				cout<<"\t\t\t\t4、读者删除"<<endl;
				cout<<"\t\t\t\t0、返回"<<endl;
				cin>>n;
				system("cls");
				switch(n)
				{
					case 1:
						{
							cout<<"\n\t\t\t\t请输入新读者的编号：";
							cin>>rnum;
							r = queryid(rnum);
							if(r != NULL)
							{
								cout<<"\n\t\t\t\t该编号已经存在，不能添加!"<<endl;
								system("pause");
								system("cls");
								break;
							}
							cout<<"\t\t\t\t请输入读者姓名：";
							cin>>rname;
							do{
								cout<<"\t\t\t\t请输入读者年龄：";
								cin>>age1;
								if(age1 < 0 || age1 >150)
									cout<<"\t\t\t\t输入有误！"<<endl;
							}while(age1 < 0 || age1 >150);
							do{
								cout<<"\t\t\t\t请输入读者性别：";
								cin>>sex1;
								if(strcmp(sex1,"man") == 1 || strcmp(sex1,"woman") == 1)
									cout<<"\t\t\t\t输入有误！"<<endl;
							}while(strcmp(sex1,"man") == 1 || strcmp(sex1,"woman") == 1);
							addreader(rnum,rname,age1,sex1);
							cout<<"\t\t\t\t添加成功！"<<endl;
							system("pause");
				         	system("cls");
							break;
						}
					case 2:
						{
							cout<<"编号"<<"\t"<<"姓名"<<"\t"<<"年龄"<<"\t"<<"性别"<<"\t\t"<<"已借书籍编号"<<"\t"<<"借书时间"<<endl;
							display();
							system("pause");
				         	system("cls");
							break;
						}
					case 3:
						{
							cout<<"\n\t\t\t\t请输入读者编号："; 
							cin>>rnum; 
							r = queryid(rnum); 
							if(r == NULL) 
							{ 
								cout<<"\t\t\t\t该读者不存在! "<<endl;
								system("pause");
								system("cls");
								break;
							} 
							updateReader(rnum);
							cout<<"\t\t\t\t修改读者成功!"<<endl;
							system("pause");
				         	system("cls");
							break;
						}
					case 4:
						{
							int t;
							do{
								cout<<"\n\t\t\t\t请选择：删除全部/个人？"<<endl;
								cout<<"\t\t\t\t1、全部"<<endl;
								cout<<"\t\t\t\t2、个人"<<endl;
								cout<<"\t\t\t\t0、返回"<<endl;
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
										cout<<"\t\t\t\t输入有误，请重新输入！"<<endl;
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
						cout<<"\t\t\t\t输入有误，请重新输入！"<<endl;
						system("pause");
					    system("cls");
			            break;
				}
			}while(n != 0);
		}
		~Reader_lib() //析构函数，将read[]写到reader.txt文件中
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
        cout<<"\n\n\t\t\t\t图书馆管理系统\n"<<endl;
        cout<<"\t\t\t\t1、图书管理"<<endl;
        cout<<"\t\t\t\t2、读者管理"<<endl;
		cout<<"\t\t\t\t3、借书"<<endl;
		cout<<"\t\t\t\t4、还书"<<endl;
        cout<<"\t\t\t\t0、退出"<<endl;
        cout<<"\t\t\t\t请选择：";
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
					cout<<"\n\t\t\t\t请输入读者编号："; 
					cin>>rnum; 
					r = rl.queryid(rnum); 
					if(r == NULL) 
					{ 
						cout<<"\t\t\t\t该读者不存在, 请注册！ "<<endl;
						system("pause");
					    system("cls");
						break;
					} 
					int bnum;
					cout<<"\t\t\t\t请输入借阅图书编号：";
					cin>>bnum;
					b = bl.query1(bnum);
					if(b == NULL)
					{
						cout<<"\t\t\t\t暂无图书！"<<endl;
						system("pause");
					    system("cls");
						break;
					}
					if(b->borrowbook() == 0) 
					{ 
						cout<<"\t\t\t\t该图书已借完，不能借书!"<<endl;
						system("pause");
					    system("cls");
						break; 
					}
					rl.borrow_book(rnum, *b);
					bl.borrow_book(bnum);
					cout<<"\t\t\t\t借书成功！"<<endl;
					system("pause");
					system("cls");
					break;
				}
			case 4:
				{
					int rnum;
					cout<<"\t\t\t\t请输入读者编号："; 
					cin>>rnum; 
					r = rl.queryid(rnum); 
					if(r == NULL) 
					{ 
						cout<<"\t\t\t\t该读者不存在, 请注册！ "<<endl;
						system("pause");
					    system("cls");
						break;
					} 
					int bnum;
					cout<<"\t\t\t\t请输入要归还图书编号:"; 
					cin>>bnum; 
					b = bl.query1(bnum); 
					if(b == NULL) 
					{
						 cout<<"\t\t\t\t不存在该图书，不能还书"<<endl; 
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
					cout<<"谢谢使用！"<<endl;
					system("pause");
					break;
				}
			default:
				cout<<"输入有误，请重新输入！"<<endl;
				system("pause");
				system("cls");
			    break; 
        }
    }while(n != 0);
}
// utf-8
int main()
{
    Main_interface mi;
    mi.display();
    return 0;
}
