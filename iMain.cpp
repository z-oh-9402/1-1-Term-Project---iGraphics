#include "iGraphics.h"

int y, y_1, r, num = 0,u = 0, length, length1 gap=0, gap1=0, hang, dialog_num;
char s[100],nme[100],dialog[2][100]={"dialog.bmp","dialog01.bmp"};
char days[100];
int index, done[10],size1,size2;
char participant[15][100];
char dua[10][100],dua1[10][100],dua2[100];
const char file[15][100] = { "Participant 1.txt", "Participant 2.txt", "Participant 3.txt", "Participant 4.txt", "Participant 5.txt", "Participant 6.txt", "Participant 7.txt", "Participant 8.txt", "Participant 9.txt", "Participant 10.txt", "Participant 11.txt", "Participant 12.txt", "Participant 13.txt", "Participant 14.txt", "Participant 15.txt"};
const char file1[15][100] = { "Participant1 1.txt", "Participant1 2.txt", "Participant1 3.txt", "Participant1 4.txt", "Participant1 5.txt", "Participant1 6.txt", "Participant1 7.txt", "Participant1 8.txt", "Participant1 9.txt", "Participant1 10.txt", "Participant1 11.txt", "Participant1 12.txt", "Participant1 13.txt", "Participant1 14.txt", "Participant1 15.txt"};
char text[3][100] = { "Enter your name:", "Enter the Dua:", "Enter your target:" };
char pic[12][100] = { "pic01.bmp", "pic02.bmp","pic03.bmp","pic04.bmp","pic05.bmp","pic06.bmp","pic07.bmp","pic08.bmp","pic09.bmp","pic10.bmp","pic11.bmp","pic12.bmp" };
int a,seq,pic_index=0;
char random1[10][5], random2[10][5], random3[15][5], random4[10][5], name[15][100],tym[100],cnt_dua[100];
char bg[3][100] = { "bg.bmp" , "bg2.bmp","istockphoto-1308682666-612x612.bmp"};
char main_bg[3][100] = { "11111.bmp" ,"112.bmp", "rm422-076.bmp"};
int bg_index = 0;
char theme[3][100];
long long tm[10],scnds;
long long tmr,plus1=86400,plus2=604800;
int tog;
bool musicOn = true, musicOn2 = true;
int count_dua[10],count_dua1[10],target[10];
int count = 0,cnt=0,cnt1=0;
time_t seconds;
int b = 0, w = 0, l, d = 0, g = 0, m = 0, f, call = 0;
char ti[30];
char *count_store = (char*)malloc(sizeof(char)* 10);
char comment[2][100] = { "Saved Successfully!!!", "Deleted Successfully!!!" };
char record[10][100];
int snd_index = 0;
char line[15][100],line1[10][100];

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

void convert_int(int n, char rdm[])
{
	int total = 0, q = n;
	if (q == 0)
	{
		total++;
	}
	else
	{
		while (q)
		{
			q = q / 10;
			total++;
		}
	}

	rdm[total] = '\0';
	while (total)
	{
		rdm[total - 1] = '0' + (n % 10);
		n = n / 10;
		total--;
	}
}

void convert_char(int *n, char rdm[])
{
	long long power = 1;
	*n = 0;
	int length = strlen(rdm) - 1;
	for (int i = length; i >= 0; i--)
	{
		*n += (rdm[i] - 48)*power;
		power = power * 10;
	}
}

void delete_file()
{
	y += 50;
	FILE *fp;
	if (num == 19)
	{
		fp = fopen("Participant1 list.txt", "r");
	}
	else
	{
		fp = fopen("Participant list.txt", "r");
	}
	for (int i = 0; i < cnt; i++)
	{
		fgets(participant[i], 100, fp);
		if (i>r)
		{
		    if(participant[i][1]>'0' && participant[i][1]<='9')
            {
                participant[i][1]--;
                continue;
            }
		    else if(participant[i][1] == '0')
            {
                participant[i][1] = '9';
                participant[i][0]--;
                continue;
            }
            else;
		}
	}
	fclose(fp);
	if (num == 19)
	{
		fp = fopen("Participant1 list.txt", "w");
	}
	else
	{
		fp = fopen("Participant list.txt", "w");
	}
	for (int i = 0; i < cnt; i++)
	{
		if (i == r)
		{
			continue;
		}
		fprintf(fp, "%s", participant[i]);
	}
	strcpy(participant[cnt - 1], "");
	fclose(fp);

	for (int i = r; i < 15; i++)
	{
		if (i == 14)
		{
			FILE *f_out;
			if (num == 19)
			{
				f_out = fopen(file1[i], "w");
			}
			else
			{
				f_out = fopen(file[i], "w");
			}
			fclose(f_out);
		}
		else
		{
			FILE *f_in;
			FILE *f_out;
			if (num == 19)
			{
				f_in = fopen(file1[i + 1], "r");
				f_out = fopen(file1[i], "w");
			}
			else
			{
				f_in = fopen(file[i + 1], "r");
				f_out = fopen(file[i], "w");
			}
			char ch = fgetc(f_in);
			while (ch != EOF)
			{
				fputc(ch, f_out);
				ch = fgetc(f_in);
			}
			fclose(f_in);
			fclose(f_out);
		}
	}
	f = 1;
	num = 13;
}

void delete_data()
{
	d = 0;
	int v = 0;
	FILE *fp;
	if (num == 26 || call == 26)
	{
		fp = fopen(file1[r], "r");
	}
	else
	{
		fp = fopen(file[r], "r");
	}
	for (int i = 0; i < cnt1; i++)
	{
		fgets(dua[i], 100, fp);
		if (i>l)
		{
		    if(dua[i][1]>'0' && dua[i][1]<='9')
            {
                dua[i][1]--;
                continue;
            }
			if(dua[i][1]=='0')
            {
                dua[i][1]='9';
                dua[i][0]--;
                continue;
            }
		}
	}
	fclose(fp);
	if (num == 26 || call==2)
	{
		fp = fopen(file1[r], "w");
	}
	else
	{
		fp = fopen(file[r], "w");
	}
	for (int i = 0; i < cnt1; i++)
	{
		if (i == l)
		{
			continue;
		}
		fprintf(fp, "%s", dua[i]);
		v = 1;
	}
	strcpy(dua[cnt1 - 1], "");
	fclose(fp);

	if (v == 1)
	{
		f = 1;
		v = 0;
	}
	else
	{
		if (num == 26 || call == 2)
		{
			fp = fopen("Participant1 list.txt", "r");
		}
		else
		{
			fp = fopen("Participant list.txt", "r");
		}
		for (int i = 0; i < cnt; i++)
		{
			fgets(participant[i], 100, fp);
			if (i>r)
			{
			    if(participant[i][1]>'0' && participant[i][1]<='9')
                {
                    participant[i][1]--;
                }
				if(participant[i][1]=='0')
                {
                    participant[i][1]='9';
                    participant[i][0]--;
                }
			}
		}
		fclose(fp);
		if (num == 26 || call == 2)
		{
			fp = fopen("Participant1 list.txt", "w");
		}
		else
		{
			fp = fopen("Participant list.txt", "w");
		}
		for (int i = 0; i < cnt; i++)
		{
			if (i == r)
			{
				continue;
			}
			fprintf(fp, "%s", participant[i]);
		}
		strcpy(participant[cnt - 1], "");
		fclose(fp);

		for (int i = r; i < 15; i++)
		{
			if (i == 14)
			{
				FILE *f_out;
				if (num == 26 || call == 2)
				{
					f_out = fopen(file1[i], "w");
				}
				else
				{
					f_out = fopen(file[i], "w");
				}
				fclose(f_out);
			}
			else
			{
				FILE *f_in;
				FILE *f_out;
				if (num==26 || call == 2)
				{
					f_in = fopen(file1[i + 1], "r");
					f_out = fopen(file1[i], "w");
				}
				else
				{
					f_in = fopen(file[i + 1], "r");
					f_out = fopen(file[i], "w");
				}
				char ch = fgetc(f_in);
				while (ch != EOF)
				{
					fputc(ch, f_out);
					ch = fgetc(f_in);
				}
				fclose(f_in);
				fclose(f_out);
			}
		}

		if (call == 18)
		{
			num = 17;
		}
		if (call == 2)
		{
			num = 13;
		}
		if (num == 26)
		{
			num = 19;
		}
	}
}

void print_name_index()
{
    call = num;
	a = 0;
	cnt = 0;
	iShowBMP2(5, 475, "109618.bmp", 0);
	iSetColor(0, 0, 0);
	int vert;
	if(num != 19)
    {
        iText(100, 400+gap, "Recent users", GLUT_BITMAP_TIMES_ROMAN_24);
        vert = 345;
    }
	else
    {
        iText(100, 440+gap, "Recent users", GLUT_BITMAP_TIMES_ROMAN_24);
        vert = 385;
    }
	FILE *m_file;
	if (call == 19)
	{
		m_file = fopen("Participant1 list.txt", "r");
	}
	else
	{
		m_file = fopen("Participant list.txt", "r");
	}
	for (int i = 0; i < 15; i++)
	{
		strcpy(participant[i], "");
		fgets(participant[i], 100, m_file);
		if (participant[i][0] < '0' || participant[i][0]>'9')
		{
			continue;
		}
		iSetColor(196, 164, 132);
		iFilledRectangle(45, vert+gap, 422, 25);
		iSetColor(0, 0, 0);
		iRectangle(45, vert+gap, 422, 25);
		iText(50, vert+5+gap, participant[i], GLUT_BITMAP_TIMES_ROMAN_24);
		vert = vert - 50;
		cnt++;
		a = 1;
	}

	fclose(m_file);

	if (a == 0)
	{
		if (num != 19)
		{
			iSetColor(0, 0, 0);
			iText(100, 256, "No such existing file.", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(60, 226, "Click Enter to create new record.", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		else
		{
			iSetColor(0, 0, 0);
			iText(100, 256, "No such existing file.", GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}

	if (u == 1 && (num == 17 || num == 19))
	{
		iShowBMP2(205, hang, dialog[dialog_num], 0);
		if(dialog_num == 0)
        {
            iText(248, hang + 48, "Rename", GLUT_BITMAP_TIMES_ROMAN_24);
            iText(248, hang + 18, "Delete", GLUT_BITMAP_TIMES_ROMAN_24);
        }
		if(dialog_num == 1)
        {
            iText(248, hang + 68, "Rename", GLUT_BITMAP_TIMES_ROMAN_24);
            iText(248, hang + 38, "Delete", GLUT_BITMAP_TIMES_ROMAN_24);
        }
	}

	if(d == 1 && (num == 17 || num == 19))
    {
        iSetColor(255, 200, 100);
		iFilledRectangle(100, 148, 295, 220);
		iSetColor(98, 45, 67);
		iRectangle(100, 148, 295, 220);
		iSetColor(0, 0, 0);
		iText(130, 324, "Would you like to delete", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(185, 294, "this record?", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(50, 50, 50);
		iFilledRectangle(140, 204, 80, 35);
		iSetColor(50, 50, 50);
		iFilledRectangle(275, 204, 80, 35);
		iSetColor(250, 255, 200);
		iText(160, 214, "YES", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255, 255, 200);
		iText(298, 214, "NO", GLUT_BITMAP_TIMES_ROMAN_24);
    }
}

void print_dua_index()
{
	a = 0;
	cnt1 = 0;
	iShowBMP2(5, 475, "109618.bmp", 0);
	iSetColor(0, 0, 0);
	FILE *fp;
	int vert;
	if (num == 26)
	{
		iText(145, 440, "Your Targets", GLUT_BITMAP_TIMES_ROMAN_24);
		vert = 385;
		fp = fopen(file1[r], "r");
	}
	else
	{
		iText(145, 420, "Your History", GLUT_BITMAP_TIMES_ROMAN_24);
		vert = 365;
		fp = fopen(file[r], "r");
	}

	for (int i = 0; i < 10; i++)
	{
		strcpy(dua[i], "");
		strcpy(random1[i], "");
		strcpy(dua1[i], "");
		strcpy(random2[i], "");
		fgets(dua[i], 100, fp);
		if (dua[i][0] < '0' || dua[i][0]>'9')
		{
			continue;
		}
		iSetColor(255, 255, 255);
		iFilledRectangle(45, vert, 422, 25);
		iSetColor(0, 0, 0);
		iRectangle(45, vert, 422, 25);
		struct tm* curr_time;
		int day=0;
		seconds = time(NULL);
		curr_time = localtime(&seconds);
		long long tmi;
		int buffer=0;
		if (num == 26)
		{
			sscanf(dua[i], "%s %s %s %d %s %d %lld %d", random1[i], dua1[i], random2[i], &count_dua[i], random4[i], &count_dua1[i], &tm[i], &done[i]);
			if (tm[i] > seconds)
			{
				tmi = tm[i] - seconds;
			}
			else
			{
				tmi = 0;
			}
			strcpy(dua[i], "");
			if (count_dua1[i] >= count_dua[i])
			{
			    buffer = 0;
				sprintf(dua[i], "%s %s %s %d", random1[i], dua1[i], random2[i], buffer);
			}
			else
			{
			    buffer = count_dua[i] - count_dua1[i];
				sprintf(dua[i], "%s %s %s %d", random1[i], dua1[i], random2[i], buffer);
			}
			if ((tmi / 86400) > 0)
			{
				day = tmi / 86400;
				tmi = tmi % 86400;
				convert_int(day, days);
				strftime(ti, 20, "%H:%M:%S", curr_time);
				if (day == 1)
				{
					strcat(days, " day ");
				}
				else
				{
					strcat(days, " days ");
				}
			}
		}
		else
		{
			sscanf(dua[i], "%s %s %s %d %s %lld", random1[i], dua1[i], random2[i], &count_dua[i], random4[i], &tm[i]);
			tmi = tm[i];
			strcpy(dua[i], "");
			sprintf(dua[i], "%s %s %s %d", random1[i], dua1[i], random2[i], count_dua[i]);
		}

		curr_time->tm_hour = tmi / 3600;
		curr_time->tm_min = (tmi % 3600) / 60;
		curr_time->tm_sec = (tmi % 3600) % 60;
		strftime(ti, 20, "%H:%M:%S", curr_time);

		if (call == 12)
		{
			iText(50, vert+5, dua1[i], GLUT_BITMAP_TIMES_ROMAN_24);
		}
		else
		{
			iText(50, vert + 5, dua[i], GLUT_BITMAP_TIMES_ROMAN_24);
			if(num == 26)
            {
                if(done[i] == 1)
                {
                    iText(50, vert + 5, dua[i], GLUT_BITMAP_TIMES_ROMAN_24);
                    iShowBMP2(432, vert, "Green Tick.bmp", 0);
                }
                else
                {
                    if(tm[i] <= seconds)
                    {
                        iShowBMP2(432, vert, "red cross.bmp", 0);
                    }
                    else
                    {
                        if (day > 0)
                        {
                            iText(330, vert + 7, days, GLUT_BITMAP_HELVETICA_18);
                        }
                        iText(392, vert + 7, ti, GLUT_BITMAP_HELVETICA_18);
                    }
                }
            }
			else
			{
				iText(392, vert + 7, ti, GLUT_BITMAP_HELVETICA_18);
			}
		}
		vert = vert - 30;
		cnt1++;
		a = 1;
	}
	fclose(fp);

	if (u == 1 && (num == 18 || num==26))
	{
		iShowBMP2(185, 210 - l * 30, "dialog1.bmp", 0);
		iText(248, 318 - l * 30, "Continue", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(248, 288 - l * 30, "Rename", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(248, 258 - l * 30, "Delete", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if (d == 1 && (num == 18 || num==26))
	{
		iSetColor(255, 200, 100);
		iFilledRectangle(100, 148, 295, 220);
		iSetColor(98, 45, 67);
		iRectangle(100, 148, 295, 220);
		iSetColor(0, 0, 0);
		iText(130, 324, "Would you like to delete", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(185, 294, "this record?", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(50, 50, 50);
		iFilledRectangle(140, 204, 80, 35);
		iSetColor(50, 50, 50);
		iFilledRectangle(275, 204, 80, 35);
		iSetColor(250, 255, 200);
		iText(160, 214, "YES", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255, 255, 200);
		iText(298, 214, "NO", GLUT_BITMAP_TIMES_ROMAN_24);
	}
}

void append_file()
{
	FILE *f_in;
	strcpy(name[0], " ");
	strcat(name[0], nme);
	strcpy(random3[0], "01.");
	if (num == 7)
	{
		f_in = fopen("Participant list.txt", "r");
	}
	else
	{
		f_in = fopen("Participant1 list.txt", "r");
	}

	for (int i = 1; i<15; i++)
	{
		fscanf(f_in, "%s", random3[i]);
		fgets(name[i], 100, f_in);
	}
	fclose(f_in);
	if (num == 7)
	{
		f_in = fopen("Participant list.txt", "w");
	}
	else
	{
		f_in = fopen("Participant1 list.txt", "w");
	}
	for (int i = 0; i < 15; i++)
	{
		if (random3[i][0] < '0' || random3[i][0] > '9')
		{
			continue;
		}
		if(i<9)
        {
            fprintf(f_in, "0%d.%s", i + 1, name[i]);
        }
		else
        {
            fprintf(f_in, "%d.%s", i + 1, name[i]);
        }
	}

	fclose(f_in);
}

void create_file()
{
	FILE *f_in;
	for (int i = 14; i > 0; i--)
	{
		FILE *f_out;
		if (num == 7)
		{
			f_in = fopen(file[i - 1], "r");
			f_out = fopen(file[i], "w");
		}
		else
		{
			f_in = fopen(file1[i - 1], "r");
			f_out = fopen(file1[i], "w");
		}

		char ch = fgetc(f_in);
		while (ch != EOF)
		{
			fputc(ch, f_out);
			ch = fgetc(f_in);
		}
		fclose(f_in);
		fclose(f_out);
	}
	if (num == 7)
	{
		f_in = fopen(file[0], "w");
		fprintf(f_in, "01. %s - %d - %lld", s, count, tmr);
	}
	else
	{
		f_in = fopen(file1[0], "w");
		if (tog == 1)
		{
			fprintf(f_in, "01. %s - %s - %d %lld 0", dua2, s, count, seconds+plus1);
		}
		if (tog == 2)
		{
			fprintf(f_in, "01. %s - %s - %d %lld 0", dua2, s, count, seconds+plus2);
		}
		strcpy(dua2, "");
	}

	fclose(f_in);
	count = 0;
	num = 13;
}

void take_input()
{
	for (int i = 0; i < 10; i++)
	{
		strcpy(random1[i], "");
	}
	FILE *fp;
	if (num == 30)
	{
		fp = fopen(file1[r], "r");
	}
	else
	{
		fp = fopen(file[r], "r");
	}
	for (int i = 0; i < 10; i++)
	{
		if (num == 30)
		{
			fscanf(fp, "%s %s %s %d %s %d %lld %d", random1[i], dua1[i], random2[i], &count_dua[i], random4[i], &count_dua1[i], &tm[i], &done[i]);
		}
		else
		{
			fscanf(fp, "%s %s %s %d %s %lld", random1[i], dua1[i], random2[i], &count_dua[i], random4[i], &tm[i]);
		}
	}
	fclose(fp);
}

void shift_data()
{
	for (int i = 9; i > 0; i--)
	{
		count_dua[i] = count_dua[i - 1];
		count_dua1[i] = count_dua1[i - 1];
		done[i] = done[i - 1];
		strcpy(dua1[i], dua1[i - 1]);
		if (random1[i - 1][0] >= '0' && random1[i - 1][0] <= '9')
		{
		    random1[i][0] = '0';
            random1[i][1] = i + 49;
			random1[i][2] = '.';
		}
		strcpy(random2[i], random2[i - 1]);
		strcpy(random4[i], random4[i - 1]);
		tm[i] = tm[i - 1];
	}
	count_dua[0] = count;
	count_dua1[0] = 0;
	done[0] = 0;
	if (num == 30)
	{
		strcpy(dua1[0], dua2);
	}
	else
	{
		strcpy(dua1[0], s);
	}
	strcpy(random1[0], "01.");
	strcpy(random2[0], "-");
	strcpy(random4[0], "-");
	if (num == 30)
	{
		if (tog == 1)
		{
			tm[0] = seconds+plus1;
		}
		if (tog == 2)
		{
			tm[0] = seconds+plus2;
		}
	}
	else
	{
		tm[0] = tmr;
	}
}

void replace_file()
{
	char temp[100];
	strcpy(temp, dua1[l]);
	int temp1=count_dua[l],temp3=count_dua1[l],temp4=done[l];
	long long temp2 = tm[l];
	for (int i = l - 1; i >= 0; i--)
	{
		strcpy(dua1[i + 1], dua1[i]);
		count_dua[i + 1] = count_dua[i];
		count_dua1[i + 1] = count_dua1[i];
		done[i + 1] = done[i];
		tm[i + 1] = tm[i];
	}
	count_dua[0] = temp1;
	count_dua1[0] = temp3;
	done[0] = temp4;
	strcpy(dua1[0], temp);
	strcpy(temp, "");
	tm[0] = temp2;

	FILE *fp;
	fp = fopen("temp.txt", "w");
	for (int i = 0; i < 10; i++)
	{
		if (random1[i][0] <='0' || random1[i][0]>'9')
		{
			continue;
		}
		if (call == 26 || num == 30 || call==30 || call == 2)
		{
			fprintf(fp, "%s %s %s %d %s %d %lld %d\n", random1[i], dua1[i], random2[i], count_dua[i], random4[i], count_dua1[i], tm[i], done[i]);
		}
		else
		{
			fprintf(fp, "%s %s %s %d %s %lld\n", random1[i], dua1[i], random2[i], count_dua[i], random4[i], tm[i]);
		}
	}
	fclose(fp);

	for (int i = r - 1; i >= 0; i--)
	{
		FILE *f_in;
		FILE *f_out;
		if (num == 30 || call == 26 || call == 30 || call == 2)
		{
			f_in = fopen(file1[i], "r");
			f_out = fopen(file1[i + 1], "w");
		}
		else
		{
			f_in = fopen(file[i], "r");
			f_out = fopen(file[i + 1], "w");
		}
		char ch = fgetc(f_in);
		while (ch != EOF)
		{
			fputc(ch, f_out);
			ch = fgetc(f_in);
		}
		fclose(f_out);
		fclose(f_in);
	}
	FILE *f_in = fopen("temp.txt", "r");
	FILE *f_out;
	if (num == 30 || call == 26 || call == 30 || call == 2)
	{
		f_out = fopen(file1[0], "w");
	}
	else
	{
		f_out = fopen(file[0], "w");
	}
	int ch = fgetc(f_in);
	while (ch != EOF)
	{
		fputc(ch, f_out);
		ch = fgetc(f_in);
	}
	fclose(f_out);
	fclose(f_in);
	int p = remove("temp.txt");

	FILE *fptr;
	if (num == 30 || call == 26 || call == 30 || call == 2)
	{
		fptr = fopen("Participant1 list.txt", "r");
	}
	else
	{
		fptr = fopen("Participant list.txt", "r");
	}
	for (int i = 0; i < 15; i++)
	{
		fgets(participant[i], 100, fptr);
	}
	participant[r][0] = '0';
	participant[r][1] = '1';
	strcpy(temp, participant[r]);
	for (int i = r - 1; i >= 0; i--)
	{
	    if(participant[i][1]>='0' && participant[i][1]<'9')
        {
            participant[i][1]++;
        }
        if(participant[i][1]=='9')
        {
            participant[i][0]++;
            participant[i][1]='0';
        }
		strcpy(participant[i + 1], participant[i]);
	}
	strcpy(participant[0], temp);
	strcpy(temp, "");
	if (num == 30 || call == 26 || call == 30 || call == 2)
	{
		fp = fopen("Participant1 list.txt", "w");
	}
	else
	{
		fp = fopen("Participant list.txt", "w");
	}
	for (int i = 0; i < 15; i++)
	{
		fprintf(fp, "%s", participant[i]);
	}
	fclose(fp);

	count = 0;
	f = 0;
	num = 13;
}

void rename()
{
    FILE *fp;
    if(call == 17)
    {
        fp=fopen("Participant list.txt","r");
    }
    else if(call == 19)
    {
        fp=fopen("Participant1 list.txt","r");
    }
    else if(call == 18)
    {
        fp=fopen(file[r],"r");
    }
    else
    {
        fp=fopen(file1[r],"r");
    }

    if(call == 17 || call == 19)
    {
        for(int i=0;i<15;i++)
        {
            fgets(line[i],100,fp);
        }
        strcpy(line[r],"");
        if(r<9)
        {
            sprintf(line[r],"0%d. %s\n",r+1,s);
        }
        else
        {
            sprintf(line[r],"%d. %s\n",r+1,s);
        }
    }

    else
    {
        for(int i=0;i<10;i++)
        {
            fgets(line1[i],100,fp);
        }
        int rand,rand1,rand7;
        long long rand2;
        char rand3[50],rand4[3],rand5[3],rand6[3];
        if(call != 18)
        {
            sscanf(line1[l],"%s %s %s %d %s %d %lld %d",rand4,rand3,rand5,&rand,rand6,&rand1,&rand2,&rand7);
            strcpy(line1[l],"");
            if(l<9)
            {
                sprintf(line1[l],"0%d. %s - %d - %d %lld %d\n",l+1,s,rand,rand1,rand2,rand7);
            }
            else
            {
                sprintf(line1[l],"%d. %s - %d - %d %lld %d\n",l+1,s,rand,rand1,rand2,rand7);
            }
        }
        else
        {
            sscanf(line1[l],"%s %s %s %d %s %lld",rand4,rand3,rand5,&rand,rand6,&rand2);
            strcpy(line1[l],"");
            if(l<9)
            {
                sprintf(line1[l],"0%d. %s - %d - %lld\n",l+1,s,rand,rand2);
            }
            else
            {
                sprintf(line1[l],"%d. %s - %d - %lld\n",l+1,s,rand,rand2);
            }
        }
        strcpy(rand3,"");strcpy(rand4,"");strcpy(rand5,"");strcpy(rand6,"");
    }
    fclose(fp);

    if(call == 17)
    {
        fp=fopen("Participant list.txt","w");
    }
    else if(call == 19)
    {
        fp=fopen("Participant1 list.txt","w");
    }
    else if(call == 18)
    {
        fp=fopen(file[r],"w");
    }
    else
    {
        fp=fopen(file1[r],"w");
    }

    if(call == 17 || call == 19)
    {
        for(int i=0;i<15;i++)
        {
            if(line[i][0]>'0' || line[i][0]<='9')
            {
                fprintf(fp,"%s",line[i]);
            }
        }
    }
    else
    {
        for(int i=0;i<10;i++)
        {
            if(line1[i][0]>'0' || line1[i][0]<='9')
            {
                fprintf(fp,"%s",line1[i]);
            }
        }
    }

    fclose(fp);
    num = call;
}

void notification()
{
    cnt = 0;
    FILE *fp=fopen("Participant1 list.txt","r");
    for(int i=0;i<15;i++)
    {
        fgets(participant[i],100,fp);
        if(participant[i][0]<='0' || participant[i][0]>'9')
        {
            continue;
        }
        cnt++;
        strcpy(participant[i],"");
    }
    fclose(fp);

    if(cnt == 0)
    {
        m=0;
        return;
    }
    else
    {
        for(int i=0;i<cnt;i++)
        {
            char dua3[10][100];
            fp=fopen(file1[i],"r");
            size1=0;
            for(int j=0;j<10;j++)
            {
                fgets(dua[j],100,fp);
                if(dua[j][0]<='0' || dua[j][0]>'9')
                {
                    continue;
                }
                int rnd,rnd1,rnd3;
                long long rnd2;
                sscanf(dua[j],"%s %s %s %d %s %d %lld %d",random1[j],dua1[j],random2[j],&rnd,random3[j],&rnd2,&rnd1,&rnd3);
                strcpy(random1[j],"");strcpy(random2[j],"");strcpy(random3[j],"");strcpy(dua1[j],"");

                if((rnd1+86400)>scnds)
                {
                    strcpy(dua3[size1],dua[j]);
                    size1++;
                }
                strcpy(dua[j],"");
            }
            fclose(fp);

            if(size1 != 0)
            {
                if(m==0)
                {
                    m=1;
                }
                fp=fopen(file1[i],"w");
                for(int k=0;k<size1;k++)
                {
                    fprintf(fp,"%s",dua3[k]);
                    strcpy(dua3[k],"");
                }
                fclose(fp);
            }

            else
            {
                char participant1[5][100];
                fp=fopen("Participant1 list","r");
                size2=0;
                for(int k=0;k<15;k++)
                {
                    fgets(participant[k],100,fp);
                    if(participant[k][0]<='0' || participant[k][0]>'9')
                    {
                        continue;
                    }
                    if(k!=i)
                    {
                        strcpy(participant1[size2],participant[k]);
                        size2++;
                    }
                }
                fclose(fp);
                fp=fopen("Participant1 list","r");
                for(int k=0;k<size2;k++)
                {
                    fprintf(fp,"%s",participant1[k]);
                }
                fclose(fp);

                for(int k=i;k<size2;k++)
                {
                    FILE *fp1;
                    fp=fopen(file1[k],"w");
                    fp1=fopen(file1[k+1],"r");

                    char c=fgetc(fp1);
                    while(c)
                    {
                        fputc(c,fp);
                        c=fgetc(fp1);
                    }

                    fclose(fp);
                    fclose(fp1);
                }

                fp=fopen(file1[size2],"w");
                fclose(fp);
            }
        }
        return;
    }
}

void before_save()
{
	iSetColor(155, 255, 255);
	iFilledRectangle(128,128, 256, 50);
	iSetColor(0, 0, 0);
	iText(148, 143, text[seq], GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP2(5, 475, "109618.bmp", 0);
}

void new_save()
{
	iSetColor(155, 255, 255);
	iFilledRectangle(128,128, 256, 50);
	iSetColor(0, 0, 0);
	iText(148, 143, s, GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP2(5, 475, "109618.bmp", 0);
}

void save_file()
{
	iShowBMP2(0, 0, bg[bg_index], -1);
	iSetColor(255, 255, 200);
	iFilledRectangle(100, 148, 295, 220);
	iSetColor(0, 0, 0);
	iRectangle(100, 148, 295, 220);
	iShowBMP2(5, 475, "109618.bmp", 0);
	if (num == 16)
	{
		iText(130, 324, "Would you like to save", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(177, 294, "before exiting?", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if (num == 14)
	{
		iText(130, 324, "The file already exists.", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(130, 294, "Would you like to update", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(177, 264, "the said file?", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if (num == 15)
	{
		iText(130, 324, "The dua already exists.", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(130, 294, "Would you like to update", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(177, 264, "the said dua?", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if (num == 31 || num==32)
	{
		iText(130, 324, "What would be the type", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(177, 294, "of your target?", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else
	{
		iText(125, 324, "Would you like to save in", GLUT_BITMAP_TIMES_ROMAN_24);
		if (num == 9)
		{
			iText(170, 294, "an existing Dua?", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (num == 3)
		{
			iText(170, 294, "an existing file?", GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}

	if (num == 31 || num==32)
	{
		iSetColor(50, 50, 50);
		iFilledRectangle(140, 204, 90, 35);
		iFilledRectangle(265, 204, 90, 35);
		iSetColor(250, 255, 200);
		iText(160, 214, "Daily", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(273, 214, "Weekly", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else
	{
		iSetColor(50, 50, 50);
		iFilledRectangle(140, 204, 80, 35);
		iFilledRectangle(275, 204, 80, 35);
		iSetColor(250, 255, 200);
		iText(160, 214, "YES", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(298, 214, "NO", GLUT_BITMAP_TIMES_ROMAN_24);
	}
}

void scan_file()
{
	FILE *fp;
	if (num == 5)
	{
		fp = fopen("Participant list.txt", "r");
	}
	else if (num == 11)
	{
		fp = fopen(file[r], "r");
	}
	else if (num==21)
	{
		fp = fopen("Participant1 list.txt", "r");
	}
	else
	{
		fp = fopen(file1[r], "r");
	}

	if (num == 5 || num==21)
	{
		for (int i = 0; i < 15; i++)
		{
			strcpy(name[i], "");
			fscanf(fp, "%s", random3[i]);
			fgets(name[i], 100, fp);
			if (strcmp(name[i], s)==0)
			{
				r = i;
				g = 1;
			}
		}
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			if (num == 11)
			{
				strcpy(dua[i], "");
				fgets(dua[i], 100, fp);
				sscanf(dua[i], "%s %s %s %d %s %lld", random1[i], dua1[i], random2[i], &count_dua[i], random4[i], &tm[i]);
				if (strcmp(dua1[i], s) == 0)
				{
					l = i;
					g = 1;
				}
			}
			else
			{
				strcpy(dua[i], "");
				fgets(dua[i], 100, fp);
				sscanf(dua[i], "%s %s %s %d %s %d %lld %d", random1[i], dua1[i], random2[i], &count_dua[i], random4[i], &count_dua1[i], &tm[i], &done[i]);
				if (strcmp(dua1[i], dua2) == 0)
				{
					l = i;
					g = 1;
				}
			}

		}
	}
	fclose(fp);
}

void iDraw()
{
	iClear();
	if (num == 0)
	{
		iShowBMP2(0, 0, main_bg[bg_index], -1);
		iShowBMP2(128, 305, "Screenshot.bmp", 0);
		iSetColor(255, 235, 255);
		iFilledRectangle(100, 240, 100, 50);
		iFilledRectangle(100, 140, 100, 50);
		iFilledRectangle(312, 240, 100, 50);
		iFilledRectangle(312, 140, 100, 50);
		iSetColor(90, 12, 200);
		iRectangle(100, 240, 100, 50);
		iRectangle(100, 140, 100, 50);
		iRectangle(312, 240, 100, 50);
		iRectangle(312, 140, 100, 50);
		iSetColor(255, 255, 255);
		time_t q;
		q = time(NULL);
		scnds=q;
		struct tm* curr_time;
		curr_time = localtime(&q);
		strftime(ti, 30, "%X  %x", curr_time);
		iText(155, 400, ti, GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(0, 0, 0);
		iText(117, 257, "Count", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(113, 157, "History", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(320, 257, "Themes", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(328, 157, "Target", GLUT_BITMAP_TIMES_ROMAN_24);

		//notification();

		if (m == 1)
		{
			iShowBMP2(385, 96, "Down Arrow.bmp", 0);
			iSetColor(255, 255, 200);
			iFilledRectangle(215, 15, 180, 115);
			iSetColor(98, 45, 67);
			iRectangle(215, 15, 180, 115);
			iText(250, 100, "There is an", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(225, 70, "unfinished goal!", GLUT_BITMAP_TIMES_ROMAN_24);
			iSetColor(255, 255, 255);
			iFilledRectangle(320, 25, 50, 20);
			iSetColor(90, 12, 200);
			iRectangle(320, 25, 50, 20);
			iText(331, 32, "VISIT", GLUT_BITMAP_TIMES_ROMAN_10);
		}
	}

	if (num == 2)
	{
		iShowBMP(0, 0, bg[bg_index]);
		iShowBMP2(5, 475, "109618.bmp", 0);
		pic_index = count % 12;
		iShowBMP2(140, 190, pic[pic_index], 0);
		iSetColor(255, 255, 255);
		iFilledRectangle(60, 80, 100, 50);
		iFilledRectangle(231, 80, 50, 50);
		iFilledRectangle(352, 80, 100, 50);
		iSetColor(9, 121, 105);
		iRectangle(60, 80, 100, 50);
		iRectangle(231, 80, 50, 50);
		iRectangle(352, 80, 100, 50);
		iSetColor(0, 0, 0);
		iText(85, 98, "Save", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(243, 98, "-1", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(372, 98, "Reset", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(0, 0, 0);
		time_t q;
		q = time(NULL);
		struct tm* curr_time;
		curr_time = localtime(&q);
		if (call == 18)
		{
			tmr = tm[l] + q - seconds;
		}
		else
		{
			tmr = q - seconds;
		}
		curr_time->tm_hour = tmr / 3600;
		curr_time->tm_min = (tmr % 3600) / 60;
		curr_time->tm_sec = (tmr % 3600) % 60;
		strftime(ti, 20, "%H:%M:%S",curr_time);
		iText(200, 480, ti, GLUT_BITMAP_TIMES_ROMAN_24);
		convert_int(count, count_store);
		if (b == 1)
		{
			iText(180, 400, dua1[l], GLUT_BITMAP_TIMES_ROMAN_24);
		}
		iText(230, 280, count_store, GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if (num == 3)
	{
		save_file();
	}

	if (num == 4)
	{
		seq = 0;
		before_save();
	}

	if (num == 5)
	{
		new_save();
	}

	if (num == 6)
	{
		seq = 1;
		before_save();
	}

	if (num == 7)
	{
		new_save();
	}

	if (num == 8)
	{
		iShowBMP(0, 0, bg[bg_index]);
		call = 8;
		print_name_index();
		length = 512 - ((cnt*50)-375);
		if(length<512)
        {
            iSetColor(200,200,200);
            iFilledRectangle(500,0,12,512);
            iSetColor(96,96,96);
            iFilledRectangle(500,y-length,12,length);
            gap = 512-y;
        }
        else
        {
            gap=0;
        }
	}

	if (num == 9)
	{
		save_file();
	}

	if (num == 10)
	{
		seq = 1;
		before_save();
	}

	if (num == 11)
	{
		new_save();
	}

	if (num == 12)
	{
		iShowBMP(0, 0, bg[bg_index]);
		call = 12;
		print_dua_index();
	}

	if (num == 13)
	{
		if (call == 2)
		{
			iSetColor(98, 45, 67);
			iFilledRectangle(100, 249, 312, 40);
			iSetColor(198, 245, 167);
			iRectangle(100, 249, 312, 40);
			iSetColor(0, 0, 0);
			iText(107, 256, "You have reached your goal!!!", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		else
		{
			iSetColor(98, 45, 67);
			iFilledRectangle(128, 249, 256, 40);
			iSetColor(198, 245, 167);
			iRectangle(128, 249, 256, 40);
			iSetColor(0, 0, 0);
			iText(135, 256, comment[f], GLUT_BITMAP_TIMES_ROMAN_24);
		}
		iSetColor(255, 255, 255);
		iText(134, 220, "Click Enter to go back.", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if (num == 14)
	{
		save_file();
	}

	if (num == 15)
	{
		save_file();
	}

	if (num == 16)
	{
		save_file();
	}

	if (num == 17)
	{
		iShowBMP(0, 0, bg[bg_index]);
		call = 17;
		print_name_index();
		length = 512 - ((cnt*50)-345);
		if(length<512)
        {
            iSetColor(200,200,200);
            iFilledRectangle(500,0,12,512);
            iSetColor(96,96,96);
            iFilledRectangle(500,y-length,12,length);
            gap = 512-y;
        }
        else
        {
            gap=0;
        }
	}

	if (num == 18)
	{
		iShowBMP(0, 0, bg[bg_index]);
		call = 18;
		print_dua_index();
		length1 = 512 - ((cnt1*30)-375);
		if(length<512)
        {
            iSetColor(200,200,200);
            iFilledRectangle(500,0,12,512);
            iSetColor(96,96,96);
            iFilledRectangle(500,y_1-length1,12,length1);
            gap = 512-y_1;
        }
        else
        {
            gap=0;
        }
	}

	if (num == 19)
	{
		iShowBMP(0, 0, bg[bg_index]);
		iShowBMP2(5, 10, "Purple Plus.bmp", 0);
		call = 19;
		print_name_index();
		length = 512 - ((cnt*50)-375);
		if(length<512)
        {
            iSetColor(200,200,200);
            iFilledRectangle(500,0,12,512);
            iSetColor(96,96,96);
            iFilledRectangle(500,y-length,12,length);
            gap = 512-y;
        }
        else
        {
            gap=0;
        }
	}

	if (num == 20)
	{
		seq = 0;
		before_save();
	}

	if (num == 21)
	{
		new_save();
	}

	if (num == 22)
	{
		seq = 1;
		before_save();
	}

	if (num == 23)
	{
		new_save();
	}

	if (num == 24)
	{
		seq = 2;
		before_save();
	}

	if (num == 25)
	{
		new_save();
	}

	if (num == 26)
	{
		iShowBMP(0, 0, bg[bg_index]);
		iShowBMP2(5, 10, "Purple Plus.bmp", 0);
		print_dua_index();
	}

	if (num == 27)
	{
		seq = 1;
		before_save();
	}

	if (num == 28)
	{
		new_save();
	}

	if (num == 29)
	{
		seq = 2;
		before_save();
	}

	if (num == 30)
	{
		new_save();
	}

	if (num == 31)
	{
		save_file();
	}

	if (num == 32)
	{
		save_file();
	}

	if (num == 33)
	{
		iShowBMP(0, 0, bg[bg_index]);
		iShowBMP2(5, 475, "109618.bmp", 0);
		iSetColor(0, 0, 0);
		iText(45, 380, "Themes:", GLUT_BITMAP_TIMES_ROMAN_24);
		FILE *fp = fopen("Themes.txt", "r");
		int vert = 280;
		for (int i = 0; i < 3; i++)
		{
			fgets(theme[i], 100, fp);
			iSetColor(255, 255, 200);
			iFilledRectangle(45, vert, 422, 40);
			iSetColor(0, 0, 43);
			iRectangle(45, vert, 422, 40);
			iText(55, vert+14, theme[i], GLUT_BITMAP_TIMES_ROMAN_24);
			vert = vert - 50;
		}

		fclose(fp);
	}
}

/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/

void iMouseMove(int mx, int my)
{
    if((num == 17 || num == 8 || num == 19) && length<512 && mx>=500)
    {
        if((512-my)<length)
        {
            y= 512;
        }
        else if(my<0)
        {
            y = length;
        }
        else
        {
            y = my + length;
        }
    }

    if((num == 12 || num == 18 || num == 26) && length<512 && mx>=500)
    {
        if((512-my)<length)
        {
            y_1 = 512;
        }
        else if(my<0)
        {
            y_1 = length;
        }
        else
        {
            y_1 = my + length;
        }
    }
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{

	if (num == 0)
	{
		if (mx >= 100 && mx <= 200 && my >= 240 && my <= 290 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			seconds = time(NULL);
			num = 2;
		}
		else if (mx >= 100 && mx <= 200 && my >= 140 && my <= 190 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
		    y=512;
			num = 17;
		}
		else if (mx >= 312 && mx <= 412 && my >= 240 && my <= 290 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 33;
		}
		else if (mx >= 312 && mx <= 412 && my >= 140 && my <= 190 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
		    y=512;
			num = 19;
			if (m == 1)
			{
				m = 2;
			}
		}

		else if (m == 1 && mx >= 320 && mx <= 370 && my >= 25 && my <= 45 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 19;
			m = 2;
		}
		else;
	}

	else if (num == 2)
	{
		if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 16;
		}
		else if (mx >= 60 && mx <= 160 && my >= 80 && my <= 130 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (b == 1)
			{
				b = 0;
				if (call == 18)
				{
					count_dua[l] = count;
					tm[l] = tmr;
					call = 0;
					replace_file();
				}
				else
				{
				    time_t scnd;
				    scnd = time(NULL);
					count_dua1[l] = count;
					if (count_dua1[l] >= count_dua[l] && tm[l] > scnd)
					{
						call = 2;
						done[l] = 1;
					}
					else
                    {
                        done[l] = 0;
                    }
					replace_file();
					num = 13;
				}
			}
			else
			{
				call = 2;
				num = 3;
			}
		}
		else if (mx >= 231 && mx <= 281 && my >= 80 && my <= 130 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (count > 0)
			{
				count--;
			}
		}
		else if (mx >= 352 && mx <= 452 && my >= 80 && my <= 130 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			count = 0;
		}
		else;
	}

	else if (num == 3)
	{
		if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 2;
		}
		else if (mx >= 140 && mx <= 220 && my >= 204 && my <= 239 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 8;
		}
		else if (mx >= 275 && mx <= 355 && my >=204  && my <= 239 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 4;
		}
		else;
	}

	else if (num == 4)
	{
		if (mx >= 128 && mx <= 128 + 256 && my >= 128 && my <= 128 + 50 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			s[0] = '\0';
			index = 0;
			num = 5;
		}
		else if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
        if(call == 17 || call == 19 )
            {
                num = call;
            }
            else
            {
                num = 3;
            }
		}
		else;
	}
	else if (num == 5)
	{
		if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 4;
		}
	}

	else if (num == 6)
	{
		if (mx >= 128 && mx <= 128 + 256 && my >= 128 && my <= 178 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			s[0] = '\0';
			index = 0;
			num = 7;
		}
		else if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
		    if(call==18 || call==26)
            {
                num=call;
            }
            else
            {
                num = 4;
            }
		}
		else;
	}

	else if (num == 7)
	{
		if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 6;
		}
	}

	else if (num == 8 && a==1)
	{
		if (mx >= 45 && mx <= 467 && my >= 345 && my <= 370 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && participant[0][0] >= '0' && participant[0][0]<='9')
		{
			r = 0;
			num = 9;
		}
		else if (mx >= 45 && mx <= 467 && my >= 295 && my <= 320 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && participant[1][0] >= '0' && participant[1][0] <= '9')
		{
			r = 1;
			num = 9;
		}
		else if (mx >= 45 && mx <= 467 && my >= 245 && my <= 270 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && participant[2][0] >= '0' && participant[2][0]<='9')
		{
			r = 2;
			num = 9;
		}
		else if (mx >= 45 && mx <= 467 && my >= 195 && my <= 220 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && participant[3][0] >= '0' && participant[3][0]<='9')
		{
			r = 3;
			num = 9;
		}
		else if (mx >= 45 && mx <= 467 && my >= 145 && my <= 170 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && participant[4][0] >= '0' && participant[4][0]<='9')
		{
			r = 4;
			num = 9;
		}
		else if (mx >= 5 && mx <= 467 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 3;
		}
	}
	else if (num == 9)
	{
		if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 8;
		}
		else if (mx >= 140 && mx <= 220 && my >= 204 && my <= 239 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 12;
		}
		else if (mx >= 275 && mx <= 355 && my >= 204 && my <= 239 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 10;
		}
		else;
	}

	else if (num == 10)
	{
		if (mx >= 128 && mx <= 128 + 256 && my >= 128 && my <= 178 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			s[0] = '\0';
			index = 0;
			num = 11;
		}
		else if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 9;
		}
		else;
	}

	else if (num == 11)
	{
		if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 10;
		}
	}

	else if (num == 12)
	{
		if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 9;
		}
		else if (mx >= 45 && mx <= 467 && my >= 365 && my <= 390 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && random1[0][0]>='0' && random1[0][0]<='9')
		{
			count_dua[0] += count;
			tm[0] = tmr;
			l = 0;
			replace_file();
		}
		else if (mx >= 45 && mx <= 467 && my >= 335 && my <= 360 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && random1[1][0]>='0' && random1[1][0] <= '9')
		{
			count_dua[1] += count;
			tm[1] = tmr;
			l = 1;
			replace_file();
		}
		else if (mx >= 45 && mx <= 467 && my >= 305 && my <= 330 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && random1[2][0]>='0' && random1[2][0] <= '9')
		{
			count_dua[2] += count;
			tm[2] = tmr;
			l = 2;
			replace_file();
		}
		else if (mx >= 45 && mx <= 467 && my >= 275 && my <= 300 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && random1[3][0]>='0' && random1[3][0] <= '9')
		{
			count_dua[3] += count;
			tm[3] = tmr;
			l = 3;
			replace_file();
		}
		else if (mx >= 45 && mx <= 467 && my >= 245 && my <= 270 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && random1[4][0]>='0' && random1[4][0] <= '9')
		{
			count_dua[4] += count;
			tm[4] = tmr;
			l = 4;
			replace_file();
		}
		else if (mx >= 45 && mx <= 467 && my >= 215 && my <= 240 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && random1[5][0]>='0' && random1[5][0] <= '9')
		{
			count_dua[5] += count;
			tm[5] = tmr;
			l = 5;
			replace_file();
		}
		else if (mx >= 45 && mx <= 467 && my >= 185 && my <= 210 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && random1[6][0]>='0' && random1[6][0] <= '9')
		{
			count_dua[6] += count;
			tm[6] = tmr;
			l = 6;
			replace_file();
		}
		else if (mx >= 45 && mx <= 467 && my >= 155 && my <= 180 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && random1[7][0]>='0' && random1[7][0] <= '9')
		{
			count_dua[7] += count;
			tm[7] = tmr;
			l = 7;
			replace_file();
		}
		else if (mx >= 45 && mx <= 467 && my >= 125 && my <= 150 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && random1[8][0]>='0' && random1[8][0] <= '9')
		{
			count_dua[8] += count;
			tm[8] = tmr;
			l = 8;
			replace_file();
		}
		else if (mx >= 45 && mx <= 467 && my >= 95 && my <= 120 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && random1[9][0]>='0' && random1[9][0] <= '9')
		{
			count_dua[9] += count;
			tm[9] = tmr;
			l = 9;
			replace_file();
		}
		else;
	}

	else if (num == 14)
	{
		if (mx >= 275 && mx <= 355 && my >= 204 && my <= 239 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 0;
			count = 0;
		}
		else if (mx >= 140 && mx <= 220 && my >= 204 && my <= 239 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (b == 1)
			{
				b = 0;
				count_dua[l] = count;
				tm[l] = tmr;
				replace_file();
			}
			else
			{
				call = 2;
				num = 3;
			}
		}
		else if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 2;
		}
	}

	else if (num == 15)
	{
		if (mx >= 275 && mx <= 355 && my >= 204 && my <= 239 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 0;
			count = 0;
		}
		else if (mx >= 140 && mx <= 220 && my >= 204 && my <= 239 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (call == 11)
			{
				count_dua[l]+=count;
				tm[l] += tmr;
				replace_file();
			}
			if (call == 30)
			{
				count_dua[l] = count;
				if (tog == 1)
				{
					tm[l] = seconds+plus1;
				}
				if (tog == 2)
				{
					tm[l] = seconds + plus2;
				}
				replace_file();
			}
		}
		else if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (call == 11)
			{
				num = 11;
			}
			else
			{
				num = 30;
			}
		}
	}

	else if (num == 16)
	{
		if (mx >= 275 && mx <= 355 && my >= 204 && my <= 239 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 0;
			count = 0;
		}
		else if (mx >= 140 && mx <= 220 && my >= 204 && my <= 239 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
		    if (b == 1)
			{
				b = 0;
				if (call == 18)
				{
					count_dua[l] = count;
					tm[l] = tmr;
					call = 0;
					replace_file();
				}
				else
				{
				    time_t scnd;
				    scnd=time(NULL);
					count_dua1[l] = count;
					if (count_dua1[l] >= count_dua[l] && tm[l]>scnd)
					{
						call = 2;
						done[l]=1;
					}
					else
                    {
                        done[l] = 0;
                    }
					replace_file();
					num = 13;
				}
			}
			else
			{
				call = 2;
				num = 3;
			}
		}
		else if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 2;
		}
	}

	else if (num == 17 && a==1)
	{
		if (mx >= 45 && mx <= 467 && my >= 345+gap && my <= 370+gap && participant[0][0]>='0' && participant[0][0] <= '9' && u == 0 && d==0)
		{
			r = 0;
			if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && d==0)
            {
                num = 18;
            }
            if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
            {
                hang = 250+gap;
                dialog_num = 0;
                u = 1;
            }
		}
		else if (mx >= 45 && mx <= 467 && my >= 295+gap && my <= 320+gap && participant[1][0]>='0' && participant[1][0] <= '9' && u == 0 && d == 0)
		{
			r = 1;
			if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && d==0)
            {
                num = 18;
            }
            if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
            {
                hang = 200+gap;
                dialog_num = 0;
                u = 1;
            }
		}
		else if (mx >= 45 && mx <= 467 && my >= 245+gap && my <= 270+gap && participant[2][0]>='0' && participant[2][0] <= '9' && u == 0 && d == 0)
		{
			r = 2;
			if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && d==0)
            {
                num = 18;
            }
            if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
            {
                hang = 150+gap;
                dialog_num = 0;
                u = 1;
            }
		}
		else if (mx >= 45 && mx <= 467 && my >= 195+gap && my <= 220+gap && participant[3][0]>='0' && participant[3][0] <= '9' && u == 0 && d == 0)
		{
			r = 3;
			if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && d==0)
            {
                num = 18;
            }
            if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
            {
                hang = 100+gap;
                dialog_num = 0;
                u = 1;
            }
		}
		else if (mx >= 45 && mx <= 467 && my >= 145+gap && my <= 170+gap && participant[4][0]>='0' && participant[4][0] <= '9' && u == 0 && d == 0)
		{
		    r = 4;
		    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && d==0)
            {
                num = 18;
            }
            if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
            {
                hang = 50+gap;
                dialog_num = 0;
                u = 1;
            }
		}
		else if (mx >= 45 && mx <= 467 && my >= 95+gap && my <= 120+gap && participant[5][0]>='0' && participant[5][0] <= '9' && u == 0 && d == 0)
		{
		    r = 5;
		    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && d==0)
            {
                num = 18;
            }
            if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
            {
                hang = 0+gap;
                dialog_num = 0;
                u = 1;
            }
		}
		else if (mx >= 45 && mx <= 467 && my >= 45+gap && my <= 70+gap && participant[6][0]>='0' && participant[6][0] <= '9' && u == 0 && d == 0)
		{
		    r = 6;
		    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && d==0)
            {
                num = 18;
            }
            if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
            {
                if((-50+gap)>=0)
                {
                    hang = -50+gap;
                    dialog_num = 0;
                }
                else
                {
                    hang = 63+gap;
                    dialog_num = 1;
                }
                u = 1;
            }
		}
		else if (mx >= 45 && mx <= 467 && my >= -5+gap && my <= 20+gap && participant[7][0]>='0' && participant[7][0] <= '9' && u == 0 && d == 0)
		{
		    r = 7;
		    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && d==0)
            {
                num = 18;
            }
            if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
            {
                if((-100+gap)>=0)
                {
                    hang = -100+gap;
                    dialog_num = 0;
                }
                else
                {
                    hang = 13+gap;
                    dialog_num = 1;
                }
                u = 1;
            }
		}
		else if (mx >= 45 && mx <= 467 && my >= -55+gap && my <= -30+gap && participant[8][0]>='0' && participant[8][0] <= '9' && u == 0 && d == 0)
		{
		    r = 8;
		    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && d==0)
            {
                num = 18;
            }
            if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
            {
                if((-150+gap)>=0)
                {
                    hang = -150+gap;
                    dialog_num = 0;
                }
                else
                {
                    hang = -37+gap;
                    dialog_num = 1;
                }
                u = 1;
            }
		}
		else if (mx >= 45 && mx <= 467 && my >= -105+gap && my <= -80+gap && participant[9][0]>='0' && participant[9][0] <= '9' && u == 0 && d == 0)
		{
		    r = 9;
		    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && d==0)
            {
                num = 18;
            }
            if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
            {
                if((-200+gap)>=0)
                {
                    hang = -200+gap;
                    dialog_num = 0;
                }
                else
                {
                    hang = -87+gap;
                    dialog_num = 1;
                }
                u = 1;
            }
		}
		else if (mx >= 45 && mx <= 467 && my >= -155+gap && my <= -130+gap && participant[10][0]>='0' && participant[10][0] <= '9' && u == 0 && d == 0)
		{
		    r = 10;
		    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && d==0)
            {
                num = 18;
            }
            if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
            {
                if((-250+gap)>=0)
                {
                    hang = -250+gap;
                    dialog_num = 0;
                }
                else
                {
                    hang = -137+gap;
                    dialog_num = 1;
                }
                u = 1;
            }
		}
		else if (mx >= 45 && mx <= 467 && my >= -205+gap && my <= -180+gap && participant[11][0]>='0' && participant[11][0] <= '9' && u == 0 && d == 0)
		{
		    r = 11;
		    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && d==0)
            {
                num = 18;
            }
            if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
            {
                if((-300+gap)>=0)
                {
                    hang = -300+gap;
                    dialog_num = 0;
                }
                else
                {
                    hang = -187+gap;
                    dialog_num = 1;
                }
                u = 1;
            }
		}
		else if (mx >= 45 && mx <= 467 && my >= -255+gap && my <= -230+gap && participant[12][0]>='0' && participant[12][0] <= '9' && u == 0 && d == 0)
		{
		    r = 12;
		    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && d==0)
            {
                num = 18;
            }
            if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
            {
                if((-350+gap)>=0)
                {
                    hang = -350+gap;
                    dialog_num = 0;
                }
                else
                {
                    hang = -237+gap;
                    dialog_num = 1;
                }
                u = 1;
            }
		}
		else if (mx >= 45 && mx <= 467 && my >= -305+gap && my <= -280+gap && participant[13][0]>='0' && participant[13][0] <= '9' && u == 0 && d == 0)
		{
		    r = 13;
		    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && d==0)
            {
                num = 18;
            }
            if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
            {
                if((-400+gap)>=0)
                {
                    hang = -400+gap;
                    dialog_num = 0;
                }
                else
                {
                    hang = -287+gap;
                    dialog_num = 1;
                }
                u = 1;
            }
		}
		else if (mx >= 45 && mx <= 467 && my >= -355+gap && my <= -330+gap && participant[14][0]>='0' && participant[14][0] <= '9' && u == 0 && d == 0)
		{
		    r = 14;
		    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && d==0)
            {
                num = 18;
            }
            if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
            {
                if((-450+gap)>=0)
                {
                    hang = -450+gap;
                    dialog_num = 0;
                }
                else
                {
                    hang = -337+gap;
                    dialog_num = 1;
                }
                u = 1;
            }
		}

		else if (u == 1 && mx >= 248 && mx <= 312 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
		    if((my >= hang + 18 && my <= hang + 32 && dialog_num == 0) || (my >= hang + 38 && my <= hang + 52 && dialog_num == 1))
            {
                d = 1;
                u = 0;
            }
		    if((my >= hang + 48 && my <= hang + 62 && dialog_num == 0) || (my >= hang + 68 && my <= hang + 82 && dialog_num == 1))
            {
                call = 17;
                num = 4;
                u = 0;
            }
		}
		else if (mx >= 140 && mx <= 220 && my >= 204 && my <= 239 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && d == 1)
		{
		    d = 0;
		    call = num;
			delete_file();
		}
		else if (mx >= 275 && mx <= 355 && my >= 204 && my <= 239 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && d == 1)
		{
			d = 0;
			num = call;
		}

		else if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (u == 1)
			{
				u = 0;
				num = 17;
			}
			else if (d == 1)
			{
				d = 0;
				num = 17;
			}
			else
			{
				num = 0;
			}
		}
		else;
	}

	else if (num == 17 && a == 0)
	{
		if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 0;
		}
	}

	else if (num == 18)
	{
		if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (u == 1)
			{
				u = 0;
				num = 18;
			}
			else if (d == 1)
			{
				d = 0;
				num = 18;
			}
			else
			{
				num = 17;
			}
		}

		if (mx >= 45 && mx <= 467 && my >= 365 && my <= 390 && button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && dua[0][0] >= '0' && dua[0][0] <= '9' && u==0)
		{
			l = 0;
			u = 1;
		}
		else if (mx >= 45 && mx <= 467 && my >= 335 && my <= 360 && button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && dua[1][0] >= '0' && dua[1][0] <= '9' && u==0)
		{
			l = 1;
			u = 1;
		}
		else if (mx >= 45 && mx <= 467 && my >= 305 && my <= 330 && button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && dua[2][0] >= '0' && dua[2][0] <= '9' && u==0)
		{
			l = 2;
			u = 1;
		}
		else if (mx >= 45 && mx <= 467 && my >= 275 && my <= 300 && button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && dua[3][0] >= '0' && dua[3][0] <= '9'&& u==0)
		{
			l = 3;
			u = 1;
		}
		else if (mx >= 45 && mx <= 467 && my >= 245 && my <= 270 && button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && dua[4][0] >= '0' && dua[4][0] <= '9' && u==0)
		{
			l = 4;
			u = 1;
		}
		else if (mx >= 45 && mx <= 467 && my >= 215 && my <= 240 && button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && dua[5][0] >= '0' && dua[5][0] <= '9' && u==0)
		{
			l = 5;
			u = 1;
		}
		else if (mx >= 45 && mx <= 467 && my >= 185 && my <= 210 && button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && dua[6][0] >= '0' && dua[6][0] <= '9' && u==0)
		{
			l = 6;
			u = 1;
		}
		else if (mx >= 45 && mx <= 467 && my >= 155 && my <= 180 && button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && dua[7][0] >= '0' && dua[7][0] <= '9' && u==0)
		{
			l = 7;
			u = 1;
		}
		else if (mx >= 45 && mx <= 467 && my >= 125 && my <= 150 && button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && dua[8][0] >= '0' && dua[8][0] <= '9' && u==0)
		{
			l = 8;
			u = 1;
		}
		else if (mx >= 45 && mx <= 467 && my >= 95 && my <= 120 && button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && dua[9][0] >= '0' && dua[9][0] <= '9' && u==0)
		{
			l = 9;
			u = 1;
		}

		else if (u == 1 && mx >= 248 && mx <= 390 && my >= 318 - l * 30 && my <= 332 - l * 30 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			count = count_dua[l];
			seconds = time(NULL);
			b = 1;
			w = 1;
			call = 18;
			num = 2;
			u = 0;
		}
		else if (u == 1 && mx >= 248 && mx <= 328 && my >= 288 - l * 30 && my <= 302 - l * 30 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			u = 0;
			call = num;
			num = 6;
		}
		else if (u == 1 && mx >= 248 && mx <= 312 && my >= 258 - l * 30 && my <= 272 - l * 30 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			d = 1;
			u = 0;
		}
		else if (mx >= 140 && mx <= 220 && my >= 204 && my <= 239 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && d == 1)
		{
			call = 18;
			delete_data();
		}
		else if (mx >= 275 && mx <= 355 && my >= 204 && my <= 239 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && d == 1)
		{
			d = 0;
			num = 18;
		}
		else;
	}

	else if (num == 19 && a == 1)
	{
		if (mx >= 5 && mx <= 37 && my >= 10 && my <= 42 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 20;
		}
		else if (mx >= 45 && mx <= 467 && my >= 345 && my <= 370 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && participant[0][0]>='0' && participant[0][0] <= '9' && u==0 && d == 0)
		{
			r = 0;
			num = 26;
		}
		else if (mx >= 45 && mx <= 467 && my >= 295 && my <= 320 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && participant[1][0]>='0' && participant[1][0] <= '9' && u==0 && d == 0)
		{
			r = 1;
			num = 26;
		}
		else if (mx >= 45 && mx <= 467 && my >= 245 && my <= 270 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && participant[2][0]>='0' && participant[2][0] <= '9' && u==0 && d == 0)
		{
			r = 2;
			num = 26;
		}
		else if (mx >= 45 && mx <= 467 && my >= 195 && my <= 220 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && participant[3][0]>='0' && participant[3][0] <= '9' && u==0 && d == 0)
		{
			r = 3;
			num = 26;
		}
		else if (mx >= 45 && mx <= 467 && my >= 145 && my <= 170 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && participant[4][0]>='0' && participant[4][0] <= '9' && u==0 && d == 0)
		{
			r = 4;
			num = 26;
		}
		else if (mx >= 45 && mx <= 467 && my >= 345 && my <= 370 && button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && participant[0][0]>='0' && participant[0][0] <= '9' && u==0)
		{
			r = 0;
			u = 1;
		}
		else if (mx >= 45 && mx <= 467 && my >= 295 && my <= 320 && button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && participant[1][0]>='0' && participant[1][0] <= '9' && u==0)
		{
			r = 1;
			u = 1;
		}
		else if (mx >= 45 && mx <= 467 && my >= 245 && my <= 270 && button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && participant[2][0]>='0' && participant[2][0] <= '9' && u==0)
		{
			r = 2;
			u = 1;
		}
		else if (mx >= 45 && mx <= 467 && my >= 195 && my <= 220 && button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && participant[3][0]>='0' && participant[3][0] <= '9' && u==0)
		{
			r = 3;
			u = 1;
		}
		else if (mx >= 45 && mx <= 467 && my >= 145 && my <= 170 && button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && participant[4][0]>='0' && participant[4][0] <= '9' && u==0)
		{
			r = 4;
			u = 1;
		}
		else if (u == 1 && mx >= 248 && mx <= 328 && my >= 298 - r * 50 && my <= 312 - r * 50 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
		    call = 19;
            num = 4;
			u = 0;
		}
		else if (u == 1 && mx >= 248 && mx <= 312 && my >= 268 - r * 50 && my <= 282 - r * 50 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			d = 1;
			u = 0;
		}
		else if (mx >= 140 && mx <= 220 && my >= 204 && my <= 239 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && d == 1)
		{
			call = 19;
			delete_file();
		}
		else if (mx >= 275 && mx <= 355 && my >= 204 && my <= 239 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && d == 1)
		{
			d = 0;
			num = 19;
		}

		else if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (d == 1)
			{
				d = 0;
				num = 19;
			}
			else if(u == 1)
            {
                u = 0;
                num = 19;
            }
			else
			{
				num = 0;
			}
		}
		else;
	}

	else if (num == 19 && a == 0)
	{
		if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 0;
		}
	}

	else if (num == 20)
	{
		if (mx >= 128 && mx <= 128 + 256 && my >= 128 && my <= 178 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			s[0] = '\0';
			index = 0;
			num = 21;
		}
		else if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 19;
		}
		else;
	}

	else if (num == 21)
	{
		if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 20;
		}
	}
	else if (num == 22)
	{
		if (mx >= 128 && mx <= 128 + 256 && my >= 128 && my <= 178 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			s[0] = '\0';
			index = 0;
			num = 23;
		}
		else if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 31;
		}
		else;
	}

	else if (num == 23)
	{
		if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 22;
		}
	}

	else if (num == 24)
	{
		if (mx >= 128 && mx <= 128 + 256 && my >= 128 && my <= 178 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			s[0] = '\0';
			index = 0;
			num = 25;
		}
		else if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 23;
		}
		else;
	}

	else if (num == 25)
	{
		if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 24;
		}
	}

	else if (num == 26)
	{
		if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (u == 1)
			{
				u = 0;
				num = 26;
			}
			else if (d == 1)
			{
				d = 0;
				num = 26;
			}
			else
			{
				num = 19;
			}
		}

		if (mx >= 45 && mx <= 467 && my >= 365 && my <= 390 && button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && dua[0][0] >= '0' && dua[0][0] <= '9' && u == 0)
		{
			l = 0;
			u = 1;
		}
		else if (mx >= 45 && mx <= 467 && my >= 335 && my <= 360 && button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && dua[1][0] >= '0' && dua[1][0] <= '9' && u == 0)
		{
			l = 1;
			u = 1;
		}
		else if (mx >= 45 && mx <= 467 && my >= 305 && my <= 330 && button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && dua[2][0] >= '0' && dua[2][0] <= '9' && u == 0)
		{
			l = 2;
			u = 1;
		}
		else if (mx >= 45 && mx <= 467 && my >= 275 && my <= 300 && button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && dua[3][0] >= '0' && dua[3][0] <= '9'&& u == 0)
		{
			l = 3;
			u = 1;
		}
		else if (mx >= 45 && mx <= 467 && my >= 245 && my <= 270 && button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && dua[4][0] >= '0' && dua[4][0] <= '9' && u == 0)
		{
			l = 4;
			u = 1;
		}
		else if (mx >= 45 && mx <= 467 && my >= 215 && my <= 240 && button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && dua[5][0] >= '0' && dua[5][0] <= '9' && u == 0)
		{
			l = 5;
			u = 1;
		}
		else if (mx >= 45 && mx <= 467 && my >= 185 && my <= 210 && button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && dua[6][0] >= '0' && dua[6][0] <= '9' && u == 0)
		{
			l = 6;
			u = 1;
		}
		else if (mx >= 45 && mx <= 467 && my >= 155 && my <= 180 && button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && dua[7][0] >= '0' && dua[7][0] <= '9' && u == 0)
		{
			l = 7;
			u = 1;
		}
		else if (mx >= 45 && mx <= 467 && my >= 125 && my <= 150 && button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && dua[8][0] >= '0' && dua[8][0] <= '9' && u == 0)
		{
			l = 8;
			u = 1;
		}
		else if (mx >= 45 && mx <= 467 && my >= 95 && my <= 120 && button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && dua[9][0] >= '0' && dua[9][0] <= '9' && u == 0)
		{
			l = 9;
			u = 1;
		}

		else if (u == 1 && mx >= 248 && mx <= 390 && my >= 318 - l * 30 && my <= 332 - l * 30 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			count = count_dua1[l];
			seconds = time(NULL);
			b = 1;
			w = 1;
			call = 26;
			num = 2;
			u = 0;
		}
		else if (u == 1 && mx >= 248 && mx <= 328 && my >= 288 - l * 30 && my <= 302 - l * 30 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			u = 0;
			call = num;
			num = 6;
		}
		else if (u == 1 && mx >= 248 && mx <= 312 && my >= 258 - l * 30 && my <= 272 - l * 30 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			d = 1;
			u = 0;
		}
		else if (mx >= 140 && mx <= 220 && my >= 204 && my <= 239 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && d == 1)
		{
			delete_data();
		}
		else if (mx >= 275 && mx <= 355 && my >= 204 && my <= 239 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && d == 1)
		{
			d = 0;
			num = 26;
		}
		else if (mx >= 5 && mx <= 37 && my >= 10 && my <= 42 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 32;
		}
	}

	else if (num == 27)
	{
		if (mx >= 128 && mx <= 128 + 256 && my >= 128 && my <= 178 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			s[0] = '\0';
			index = 0;
			num = 28;
		}
		else if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 32;
		}
		else;
	}

	else if (num == 28)
	{
		if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 27;
		}
	}

	else if (num == 29)
	{
		if (mx >= 128 && mx <= 128 + 256 && my >= 128 && my <= 178 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			s[0] = '\0';
			index = 0;
			num = 30;
		}
		else if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 28;
		}
		else;
	}

	else if (num == 30)
	{
		if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 29;
		}
	}

	else if (num == 31)
	{
		if (mx >= 140 && mx <= 230 && my >= 204 && my <= 239 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			tog = 1;
			num = 22;
		}

		else if (mx >= 265 && mx <= 355 && my >= 204 && my <= 239 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			tog = 2;
			num = 22;
		}

		else if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 21;
		}
	}

	else if (num == 32)
	{
		if (mx >= 140 && mx <= 230 && my >= 204 && my <= 239 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			tog = 1;
			num = 27;
		}

		else if (mx >= 265 && mx <= 355 && my >= 204 && my <= 239 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			tog = 2;
			num = 27;
		}

		else if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 26;
		}
	}

	else if (num == 33)
	{
		if (mx >= 5 && mx <= 37 && my >= 475 && my <= 507 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			num = 0;
		}
		else if (mx >= 45 && mx <= 467 && my >= 280 && my <= 320 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			bg_index = 0;
		}
		else if (mx >= 45 && mx <= 467 && my >= 230 && my <= 270 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			bg_index = 1;
		}
		else if (mx >= 45 && mx <= 467 && my >= 180 && my <= 220 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			bg_index = 2;
		}
	}

	else;
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == '\b')
	{
		index--;
		s[index] = '\0';
	}
	else
	{
		if (key == ' ' && num==2)
		{
			count++;
		}

		else if (key == '\r')
		{
			if (num == 5)
			{
				if(call == 17 || call == 19)
                {
                    rename();
                }
                else
                {
                    s[index] = '\n';
                    index++;
                    s[index] = '\0';
                    scan_file();
                    if (g == 0)
                    {
                        strcpy(nme, "");
                        strcpy(nme, s);
                        num = 6;
                    }
                    else
                    {
                        call = 5;
                        num = 14;
                        g = 0;
                    }
                }
			}
			if (num == 7)
			{
			    if(call == 18 || call == 26)
                {
                    rename();
                }
                else
                {
                    append_file();
                    create_file();
                    f = 0;
                }
			}
			if (num == 8 && a == 0)
			{
				num = 4;
			}
			if (num == 11)
			{
				scan_file();
				if (g == 0)
				{
					l = 0;
					take_input();
					shift_data();
					replace_file();
				}
				else
				{
					call = 11;
					num = 15;
					g = 0;
				}
			}
			if (num == 12 && a==0)
			{
				num = 10;
			}
			if (num == 13)
			{
				if (f == 0)
				{
					num = 0;
				}
				else
				{
					if (call == 17)
					{
						num = 17;
					}
					else
					{
						num = 19;
					}
				}
			}
			if (num == 14 && a == 0)
			{
				num = 0;
			}
			if (num == 17 && a == 0)
			{
				num = 0;
			}
			if (num == 19 && a == 0)
			{
				num = 0;
			}
			if (num == 21)
			{
				s[index] = '\n';
				index++;
				s[index] = '\0';
				scan_file();
				if (g == 0)
				{
					strcpy(nme, "");
					strcpy(nme, s);
					num = 31;
				}
				else
				{
					call = 21;
					num = 14;
					g = 0;
				}
			}
			if (num == 23)
			{
				strcpy(dua2, s);
				num = 24;
			}
			if (num == 25)
			{
				seconds = time(NULL);
				append_file();
				create_file();
				f = 0;
			}
			if (num == 28)
			{
				strcpy(dua2, s);
				num = 29;
			}
			if (num == 30)
			{
				seconds = time(NULL);
				convert_char(&count, s);
				scan_file();
				if (g == 0)
				{
					l = 0;
					take_input();
					shift_data();
					replace_file();
					f = 0;
				}
				else
				{
					call = 30;
					num = 15;
					g = 0;
				}
			}
		}
		else if (key<1)
		{
			index = 0;
		}
		else
		{
			s[index] = key;
			index++;
			s[index] = '\0';
		}
	}
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{


	if (key == GLUT_KEY_RIGHT)
	{

	}
	if (key == GLUT_KEY_LEFT)
	{

	}

	if (key == GLUT_KEY_HOME)
	{

	}

}


int main()
{
	iInitialize(512, 512, "Tasbeeh Count");
	return 0;
}
