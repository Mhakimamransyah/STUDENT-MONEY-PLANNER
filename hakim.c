#include<stdio.h>
#include<math.h>
#include<windows.h>
int waktu(int n);
void scrabel(char s,char x);
void habis();
void open();
void main()
{
    system("COLOR 9B");
    FILE *file;
    float money,primary,object,masukan,in,out,i;
    int code,days,week,month,j;
    char time[100],act[100],act1,word[100],act2,act3[100],resume[100],day;
    char help[100],s,x;
    open();
    system("cls");
    printf("----------------STUDENTS MONEY PLANNER-------------------\t\n");
    printf("masukkan kode perencanaan\n1 untuk perencanaan pembelian objek\n2 mengolah pengeluaran\n");
    printf("3.game\n\n");
    printf("----------------create_by_M_hakim_Amransyah----------------\n");
    scanf("%d",&code);
    system("cls");
    switch(code)
    {
        case 1: printf("#anda memilih perencanaan pembelian objek\n\n"); break;
        case 2: printf("#anda memilih pengolahan pengeluaran\n\n"); break;
        case 3: printf("#game\n\n"); break;
    }
    if(code==1)
    {
       printf("help?(yes/no)                                                   :");
       scanf("%s",help);
       system("cls");
       if(strcmp(help,"yes")==0)
       {
           printf("sub program pertama ini mencoba mengolah sisa pemasukan anda yang dipotong\n");
           printf("kebutuhan sehari-hari untuk membeli sebuah objek dengan cara menabungkan sisa \n");
           printf("sisa pemasukan anda,selain itu tanda negatif artinya defisit\n");
           printf("enter untuk lanjut");
           getch();
           main();
       }
       else
       {
       printf("*format pemasukan dalam per (hari/minggu/bulan) atau keluar         :");
       scanf("%s",time);
       if(strcmp(time,"hari")==0)
       {

           printf("anda membutuhkan waktu %d hari untuk mencapai objek tersebut",waktu(day));
           getch();
       }
       else if(strcmp(time,"minggu")==0)
       {
           printf("anda membutuhkan waktu %d minggu untuk mencapai objek tersebut",waktu(week));
           getch();
       }
       else if(strcmp(time,"bulan")==0)
       {

           printf("anda membutuhkan waktu %d bulan untuk mencapai objek tersebut",waktu(month));
           getch();
       }
       else if(strcmp(time,"keluar")==0)
       {
           main();
       }
       system("pause");
       main();
       }
}
else if(code==2)
 {
  printf("help(yes/no):"); scanf("%s",help);
  system("cls");
  if(strcmp(help,"yes")==0)
  {
      printf("subprogram ini mencoba untuk melaporkan pengeluaran anda\n");
      printf("dengan menampilkan pemasukan seminggu , lalu memperlihatkan\n");
      printf("sisa uang anda.selain itu,anda juga dapat mencatat pengeluaran per hari\n");
      printf("lalu menampilkannya lagi pada saat mengakses subprogram ini dengan pilihan\n");
      printf("'resume'\n");
      printf("enter untuk lanjut");
      getch();
      main();
  }
  else
  {
  printf("resume(iya/tidak) "); scanf("%s",resume);
  system("cls");
  if(strcmp(resume,"iya")==0)
  {
      file=fopen("STDMP.txt","r");
      fread(&i,sizeof(i),1,file);
      printf("saldo terakhir=%f\n",i);
      printf("tenteukan hari kemarin:\n");
      printf("1.senin  3.rabu  5.jumat 7.minggu\n2.selasa 4.kamis 6.sabtu\n"); scanf("%d",&days);
      system("cls");
      switch(days)
    {
    case 1: printf("--selasa--\n"); break;
    case 2: printf("--rabu--\n");  break;
    case 3: printf("--kamis--\n"); break;
    case 4: printf("--jumat--\n"); break;
    case 5: printf("--sabtu--\n"); break;
    case 6: printf("--minggu--\n"); break;
    }
    if(days==1)
    {
       goto aftersenin;
    }
    else if(days==2)
    {
        printf("saldo=%f\n",i);
        goto afterselasa;
    }
    else if(days==3)
    {
        printf("saldo=%f\n",i);
        goto afterrabu;
    }
    else if(days==4)
    {
        printf("saldo=%f\n",i);
        goto afterkamis;
    }
    else if(days==5)
    {
        printf("saldo=%f\n",i);
        goto afterjumat;
    }
    else if(days==6)
    {
        printf("saldo=%f\n",i);
        goto aftersabtu;
    }
    else
    {
        printf("saldo=%f",i);
        goto afterminggu;
    }
      fclose(file);
  }
  else
  {
  printf("masukkan pemasukkan anda per minggu "); scanf("%f",&masukan);
  }
  printf("\n--senin--\n");
  i=masukan;
   afterminggu:do
   {
        file=fopen("STDMP.txt","w");
        printf("*pengeluaran= "); scanf("%f",&out);
        i=i-out;
        printf("*simpan dan keluar(iya/tidak)"); scanf("%s",act3);
        if(strcmp(act3,"iya")==0)
        {
            printf("saldo=%f\n",i);
            fwrite(&i,sizeof(i),2,file);
            fclose(file);
            system("pause");
            main();
        }
        printf("ingin melanjutkan pengeluaran?(y/n)"); scanf("%s",&act1);
        if(i<=0)
        {
            habis();
        }
   }
    while(i>=0&&act1=='y'||act1=='Y');
    printf("saldo=%f\n\n",i);


    printf("--selasa--\n");
    aftersenin:do
    {
        file=fopen("STDMP.txt","w");
        printf("*pengeluaran= "); scanf("%f",&out);
        i=i-out;
        printf("*simpan dan keluar(iya/tidak)"); scanf("%s",act3);
        if(strcmp(act3,"iya")==0)
        {
            printf("saldo=%f\n",i);
            fwrite(&i,sizeof(i),2,file);
            fclose(file);
            system("pause");
            main();
        }
        else
        {
        printf("*ingin melanjutkan pengeluaran?(y/n)"); scanf("%s",&act1);
        if(i<=0)
        {
            habis();
        }
        }

    }
    while(i>=0&&act1=='y'||act1=='Y');
    printf("saldo=%f\n\n",i);

    printf("--rabu--\n");
    afterselasa:do
    {
        file=fopen("STDMP.txt","w");
        printf("*pengeluaran= "); scanf("%f",&out);
        i=i-out;
        printf("*simpan dan keluar(iya/tidak)"); scanf("%s",act3);
        if(strcmp(act3,"iya")==0)
        {
            printf("*saldo=%f\n",i);
            fwrite(&i,sizeof(i),2,file);
            fclose(file);
            system("pause");
            main();
        }
        printf("ingin melanjutkan pengeluaran?(y/n)"); scanf("%s",&act1);
        if(i<=0)
        {
            habis();
        }

    }
    while(i>=0&&act1=='y'||act1=='Y');
    printf("saldo=%f\n\n",i);

    printf("--kamis--\n");
    afterrabu:do
    {
        file=fopen("STDMP.txt","w");
        printf("pengeluaran= "); scanf("%f",&out);
        i=i-out;
        printf("*simpan dan keluar(iya/tidak)"); scanf("%s",act3);
        if(strcmp(act3,"iya")==0)
        {
            printf("saldo=%f\n",i);
            fwrite(&i,sizeof(i),2,file);
            fclose(file);
            system("pause");
            main();
        }
        printf("ingin melanjutkan pengeluaran?(y/n)"); scanf("%s",&act1);
        if(i<=0)
        {
            habis();
        }

    }
    while(i>=0&&act1=='y'||act1=='Y');
    printf("saldo=%f\n\n",i);

    printf("--jumat--\n");
    afterkamis:do
    {
        file=fopen("STDMP.txt","w");
        printf("pengeluaran= "); scanf("%f",&out);
        i=i-out;
        printf("*simpan dan keluar(iya/tidak)"); scanf("%s",act3);
        if(strcmp(act3,"iya")==0)
        {
            printf("saldo=%f\n",i);
            fwrite(&i,sizeof(i),2,file);
            fclose(file);
            system("pause");
            main();
        }
        printf("ingin melanjutkan pengeluaran?(y/n)"); scanf("%s",&act1);
        if(i<=0)
        {
            habis();
        }

    }
    while(i>=0&&act1=='y'||act1=='Y');
    printf("saldo=%f\n\n",i);

    printf("--sabtu--\n");
    afterjumat:do
    {
        file=fopen("STDMP.txt","w");
        printf("pengeluaran= "); scanf("%f",&out);
        i=i-out;
        printf("*simpan dan keluar(iya/tidak)"); scanf("%s",act3);
        if(strcmp(act3,"iya")==0)
        {
            printf("saldo=%f\n",i);
            fwrite(&i,sizeof(i),2,file);
            fclose(file);
            system("pause");
            main();
        }
        printf("ingin melanjutkan pengeluaran?(y/n)"); scanf("%s",&act1);
        if(i<=0)
        {
            habis();
        }

    }
    while(i>=0&&act1=='y'||act1=='Y');
    printf("saldo=%f\n\n",i);

    printf("--minggu--");
    aftersabtu:do
    {
        file=fopen("STDMP.txt","w");
        printf("pengeluaran= "); scanf("%f",&out);
        i=i-out;
        printf("*simpan dan keluar(iya/tidak)"); scanf("%s",act3);
        if(strcmp(act3,"iya")==0)
        {
            printf("saldo=%f\n",i);
            fwrite(&i,sizeof(i),2,file);
            fclose(file);
            system("pause");
            main();
        }
        printf("ingin melanjutkan pengeluaran?(y/n)"); scanf("%s",&act1);
        if(i<=0)
        {
            habis();
        }

    }
    while(i>=0&&act1=='y'||act1=='Y');
    printf("saldo=%f\n\n",i);
   }
 }
    else if(code==3)
     {
        printf("   ----level 1----\n");
        printf("{5 variabel pertama(a-e)}\n\n");
        printf("_a_e\n");
        x='c';
        printf("kata pertama= "); scanf("%s",&s);
        if(s!='c')
        {
            scrabel(s,x);
        }
        x='b';
        system("cls");
        printf("ca_e\n");
        printf("kata kedua= "); scanf("%s",&s);
        if(s!='b')
        {
            scrabel(s,x);
        }
        printf("cabe\n   ----GOOD----\n");
        getch();
        system("cls");
        printf("   ----level 2----\n");
        printf("{5 variabel kedua(a-j)}\n\n");
        printf("c_e!,si entong tukang _ah_ udah g__e \n");
        x='i';
        printf("kata pertama= "); scanf("%s",&s);
        if(s!='i')
        {
            scrabel(s,x);
        }
        system("cls");
        printf("cie!,si entong tukang _ah_ udah g__e\n");
        printf("kata kedua= "); scanf("%s",&s);
        x='j';
        if(s!='j')
        {
            scrabel(s,x);
        }
        system("cls");
        printf("cie!,si entong tukang jah_ udah g___\n");
        printf("kata ketiga: "); scanf("%s",&s);
        x='e';
        if(s!='e')
        {
            scrabel(s,x);
        }
        system("cls");
        printf("cie!,si entong tukang jahe udah ge_e\n");
        printf("kata keempat: "); scanf("%s",&s);
        x='d';
        if(s!='d')
        {
            scrabel(s,x);
        }
        printf("cie!,si entong tukang jahe udah gede\n   ----NICE BUDDY----\n");
        getch();
        system("cls");
        printf("       ----level 3----\n");
        printf("{16 variabel selanjutnya(a-z) dengan angka(1-10}\n\n");
        printf("d__a 1_,k__s_r di _nd_a_a_a\n");
        x='e';
        printf("kata pertama: ");scanf("%s",&s);
        if(s!='e')
        {
            scrabel(s,x);
        }
        system("cls");
        printf("de_a 1_,k__ser di _nd_a_a_a\n");
        printf("kata kedua: ");scanf("%s",&s);
        x='w';
        if(s!='w')
        {
            scrabel(s,x);
        }
        system("cls");
        printf("dewa 1_,k__ser di _nd_a_a_a\n");
        printf("variabel= "); scanf("%s",&s);
        x='9';
        if(s!='9')
        {
            scrabel(s,x);
        }
        system("cls");
        printf("dewa 19,k__ser di _nd_a_a_a\n");
        printf("kata ketiga: "); scanf("%s",&s);
        x='o';
        if(s!='o')
        {
            scrabel(s,x);
        }
        system("cls");
        printf("dewa 19,ko_ser di _nd_a_a_a\n");
        printf("kata keempat: "); scanf("%s",&s);
        x='n';
        if(s!='n')
        {
            scrabel(s,x);
        }
        system("cls");
        printf("dewa 19,konser di _nd_a_a_a\n");
        printf("kata keempat: "); scanf("%s",&s);
        x='i';
        if(s!='i')
        {
            scrabel(s,x);
        }
        system("cls");
        printf("dewa 19,konser di ind_a_a_a\n");
        printf("kata kelima: "); scanf("%s",&s);
        x='r';
        if(s!='r')
        {
            scrabel(s,x);
        }

        system("cls");
        printf("dewa 19,konser di indra_a_a\n");
        printf("kata keenam: "); scanf("%s",&s);
        x='l';
        if(s!='r')
        {
            scrabel(s,x);
        }
        system("cls");
        printf("dewa 19,konser di indralaya\n   ----Genius!!----\n");
        getch();
        system("cls");
        printf(" ----final level----\n");
        printf("      {umum}\n\n");
        printf("_a\n");
        printf("kata awal: "); scanf("%s",&s);
        x='r';
        if(s!='r')
        {
            scrabel(s,x);
        }
        printf("ra(dewa matahari versi bangsa yunani)\n");
        printf("----congrats you're god---");
        getch();
        main();
    }
 }
int waktu(int n)
{
    float object,primary,masukan,total,total1,total2;
    int day,week,month;
    printf("*masukkan pemasukan anda                                        = "); scanf("%f",&masukan);
    printf("*masukkan kemungkinan potongan kebutuhan pokok anda(satuan hari)= "); scanf("%f",&primary);
    printf("masukkan objek yang ingin di capai                              = "); scanf("%f",&object);
    total=masukan-primary;
    total1=masukan-(primary*7);
    total2=masukan-(primary*30);
    month=object/total2;
    week=(object/total1);
    day=(object/total);
    return day;
    return week;
    return month;
}
void habis()
{
    printf("saldo habis\n");
    system("pause");
    main();
}
void scrabel(char s,char x)
{
    int j;
    j=2;
    do
    {
        if(j>3)
         {
           printf("game over");
           getch();
           main();
        }
        printf("salah,percobaan ke-%d: ",j); scanf("%s",&s);
        j++;
    }
    while(s!=x);
}
void open()
{
    int i;
    char j[22]={"Thank for using myAPPS"};
    for(i=0;i<23;i++)
    {
        printf("\n%c",j[i]);
        Sleep(100);
    }

}
