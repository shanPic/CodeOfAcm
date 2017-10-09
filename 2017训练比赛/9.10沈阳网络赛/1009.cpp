/*
* @Author: LyuC
* @Date:   2017-09-10 13:27:49
* @Last Modified by:   LyuC
* @Last Modified time: 2017-09-10 15:54:47
*/
#include <bits/stdc++.h>

#define MAXN 15

using namespace std;

int t;
int a[MAXN][MAXN];
int d[MAXN][MAXN];
int cur[MAXN];//替换数组

bool flag;

bool ok(){
    for(int i=2;i<=8;i++){
        for(int j=2;j<=9;j++){
            if(d[i][j]!=d[i][j-1])
                return false;
        }
    }
    return true;
}

void rec(){
    for(int i=1;i<=8;i++){
        for(int j=1;j<=9;j++){
            d[i]=a[i];
        }
    }
}

void opR(){
    //10 1 3 2 6 5->45 68 69 70 71 72
    //45 68 69 70 71 72->59 27 26 22 21 19
    //59 27 26 22 21 19->10 1 3 2 6 5
    int cur1[7],cur2[7],cur3[7];
    cur1[1]=10; cur1[2]=1; cur1[3]=3; cur1[4]=2; cur1[5]=6; cur1[6]=5; 
    cur2[1]=45; cur2[2]=68; cur2[3]=69; cur2[4]=70; cur2[5]=71; cur2[6]=72; 
    cur3[1]=59; cur3[2]=27; cur3[3]=26; cur3[4]=22; cur3[5]=21; cur3[6]=19; 
    for(int i=1;i<=6;i++){
        swap(d[cur1[i]],d[cur2[i]]);
    }
    for(int i=1;i<=6;i++){
        swap(d[cur1[i]],d[cur3[i]]);
    }
  
    // 28 -> 36-> 32-> 28

    // 30->31->35->34->33->29->30


}

void opL(){
    // 41 9 8 4 3 1->28 19 21 20 24 23
    // 28 19 21 20 24 23-> 63 50 51 52 53 54
    // 63 50 51 52 53 54->41 9 8 4 3 1
    int cur1[7],cur2[7],cur3[7];
    cur1[1]=41; cur1[2]=9; cur1[3]=8; cur1[4]=4; cur1[5]=3; cur1[6]=1; 
    cur2[1]=28; cur2[2]=19; cur2[3]=21; cur2[4]=20; cur2[5]=24; cur2[6]=23; 
    cur3[1]=63; cur3[2]=50; cur3[3]=51; cur3[4]=52; cur3[5]=53; cur3[6]=54; 
    for(int i=1;i<=6;i++){
        swap(d[cur1[i]],d[cur2[i]]);
    }
    for(int i=1;i<=6;i++){
        swap(d[cur1[i]],d[cur3[i]]);
    }

    //10->14->18->10
    
    // 11->15->16->17->13->12->11
}

void opML(){
    // 7 6 2 ->31 30 29
    // 31 30 29 -> 22 26 25
    // 22 26 25 -> 61 62 58 
    // 61 62 58 -> 47 48 49
    // 47 48 49 -> 38 42 43
    // 38 42 43 -> 7 6 2 
    int cur1[4],cur2[4],cur3[4],cur4[4],cur5[4],cur6[4],tmp[4];
    cur1[1]=7; cur1[2]=6; cur1[3]=2; 
    cur2[1]=31; cur2[2]=30; cur2[3]=29; 
    cur3[1]=22; cur3[2]=26; cur3[3]=25; 
    cur4[1]=61; cur4[2]=62; cur4[3]=58; 
    cur5[1]=47; cur5[2]=48; cur5[3]=49; 
    cur6[1]=38; cur6[2]=42; cur6[3]=43; 
    for(int i=1;i<=3;i++) tmp[i]=cur6[i];
    for(int i=1;i<=3;i++){
        swap(d[cur1[i]],tmp[i]);
    }
    for(int i=1;i<=3;i++){
        swap(d[cur2[i]],tmp[i]);
    }
    for(int i=1;i<=3;i++){
        swap(d[cur3[i]],tmp[i]);
    }
    for(int i=1;i<=3;i++){
        swap(d[cur4[i]],tmp[i]);
    }
    for(int i=1;i<=3;i++){
        swap(d[cur5[i]],tmp[i]);
    }
    for(int i=1;i<=3;i++){
        swap(d[cur6[i]],tmp[i]);
    }

}

void opMR(){
    // 4 8 7->43 44 40
    // 43 44 40->65 66 67
    // 65 66 67->56 60 61
    // 56 60 61->25 20 22
    // 25 20 22 -> 13 12 11
    // 13 12 11->4 8 7
    int cur1[4],cur2[4],cur3[4],cur4[4],cur5[4],cur6[4],tmp[4];
    cur1[1]=4; cur1[2]=8; cur1[3]=7; 
    cur2[1]=43; cur2[2]=44; cur2[3]=40; 
    cur3[1]=65; cur3[2]=66; cur3[3]=67; 
    cur4[1]=56; cur4[2]=60; cur4[3]=61; 
    cur5[1]=25; cur5[2]=20; cur5[3]=22; 
    cur6[1]=13; cur6[2]=12; cur6[3]=11; 
    for(int i=1;i<=3;i++) tmp[i]=cur6[i];
    for(int i=1;i<=3;i++){
        swap(d[cur1[i]],tmp[i]);
    }
    for(int i=1;i<=3;i++){
        swap(d[cur2[i]],tmp[i]);
    }
    for(int i=1;i<=3;i++){
        swap(d[cur3[i]],tmp[i]);
    }
    for(int i=1;i<=3;i++){
        swap(d[cur4[i]],tmp[i]);
    }
    for(int i=1;i<=3;i++){
        swap(d[cur5[i]],tmp[i]);
    }
    for(int i=1;i<=3;i++){
        swap(d[cur6[i]],tmp[i]);
    }

}

void opRR(){
    // 5 6 2 3 1 10->19 21 22 26 27 59
    // 19 21 22 26 27 59->72 71 70 69 68 45
    // 72 71 70 69 68 45->10 1 3 2 6 5
    int cur1[7],cur2[7],cur3[7];
    cur1[1]=5; cur1[2]=6; cur1[3]=2; cur1[4]=3; cur1[5]=1; cur1[6]=10; 
    cur2[1]=19; cur2[2]=21; cur2[3]=22; cur2[4]=26; cur2[5]=27; cur2[6]=59; 
    cur3[1]=72; cur3[2]=71; cur3[3]=70; cur3[4]=69; cur3[5]=68; cur3[6]=45; 
    for(int i=1;i<=6;i++){
        swap(d[cur1[i]],d[cur2[i]]);
    }
    for(int i=1;i<=6;i++){
        swap(d[cur1[i]],d[cur3[i]]);
    }

    // 28->32->36->28

    // 30->29->33->34->35->31->30
}

void opRL(){
    // 1 3 4 8 9 41->54 53 52 51 50 63
    // 54 53 52 51 50 63->23 24 20 21 19 28
    // 23 24 20 21 19 28->1 3 4 8 9 41

    int cur1[7],cur2[7],cur3[7];
    cur1[1]=1; cur1[2]=3; cur1[3]=4; cur1[4]=8; cur1[5]=9; cur1[6]=41; 
    cur2[1]=54; cur2[2]=53; cur2[3]=52; cur2[4]=51; cur2[5]=50; cur2[6]=63; 
    cur3[1]=23; cur3[2]=24; cur3[3]=20; cur3[4]=21; cur3[5]=19; cur3[6]=28; 
    for(int i=1;i<=6;i++){
        swap(d[cur1[i]],d[cur2[i]]);
    }
    for(int i=1;i<=6;i++){
        swap(d[cur1[i]],d[cur3[i]]);
    }

    //10->18->14->10

    // 11-> 12->13->17->16->15->11
}

void opRML(){
    //2 6 7->43 42 38
    //43 42 38->49 48 47
    //49 48 47->58 62 61
    // 58 62 61->25 26 22
    // 25 26 22->29 30 31
    //29 30 31->2 6 7
    int cur1[4],cur2[4],cur3[4],cur4[4],cur5[4],cur6[4],tmp[4];
    cur1[1]=2; cur1[2]=6; cur1[3]=7; 
    cur2[1]=43; cur2[2]=42; cur2[3]=38; 
    cur3[1]=49; cur3[2]=48; cur3[3]=47; 
    cur4[1]=58; cur4[2]=62; cur4[3]=61; 
    cur5[1]=25; cur5[2]=26; cur5[3]=22; 
    cur6[1]=29; cur6[2]=30; cur6[3]=31; 
    for(int i=1;i<=3;i++) tmp[i]=cur6[i];
    for(int i=1;i<=3;i++){
        swap(d[cur1[i]],tmp[i]);
    }
    for(int i=1;i<=3;i++){
        swap(d[cur2[i]],tmp[i]);
    }
    for(int i=1;i<=3;i++){
        swap(d[cur3[i]],tmp[i]);
    }
    for(int i=1;i<=3;i++){
        swap(d[cur4[i]],tmp[i]);
    }
    for(int i=1;i<=3;i++){
        swap(d[cur5[i]],tmp[i]);
    }
    for(int i=1;i<=3;i++){
        swap(d[cur6[i]],tmp[i]);
    }

}

void opRMR(){
    // 7 8 4->11 12 13
    // 11 12 13->22 20 25
    // 22 20 25->61 60 56
    // 61 60 56->67 66 65
    // 40 44 43->7 8 4

    // 7 8 4->11 12 13
    // 11 12 13->22 20 25
    // 22 20 25->61 60 56
    // 61 60 56->67 66 65
    // 67 66 65->40 44 43
    // 40 44 43->7 8 4
    int cur1[4],cur2[4],cur3[4],cur4[4],cur5[4],cur6[4],tmp[4];
    cur1[1]=7; cur1[2]=8; cur1[3]=4; 
    cur2[1]=11; cur2[2]=12; cur2[3]=13; 
    cur3[1]=22; cur3[2]=20; cur3[3]=25; 
    cur4[1]=61; cur4[2]=60; cur4[3]=56; 
    cur5[1]=67; cur5[2]=66; cur5[3]=65; 
    cur6[1]=40; cur6[2]=44; cur6[3]=43; 
    for(int i=1;i<=3;i++) tmp[i]=cur6[i];
    for(int i=1;i<=3;i++){
        swap(d[cur1[i]],tmp[i]);
    }
    for(int i=1;i<=3;i++){
        swap(d[cur2[i]],tmp[i]);
    }
    for(int i=1;i<=3;i++){
        swap(d[cur3[i]],tmp[i]);
    }
    for(int i=1;i<=3;i++){
        swap(d[cur4[i]],tmp[i]);
    }
    for(int i=1;i<=3;i++){
        swap(d[cur5[i]],tmp[i]);
    }
    for(int i=1;i<=3;i++){
        swap(d[cur6[i]],tmp[i]);
    }

}

void opU(){
    // 5 6 7 8 9 14->54 53 49 48 46 55
    // 54 53 49 48 46 55->64 66 65 69 68
    // 64 66 65 69 68 36 -> 5 6 7 8 9 14
    int cur1[7],cur2[7],cur3[7];
    cur1[1]=5; cur1[2]=6; cur1[3]=7; cur1[4]=8; cur1[5]=9; cur1[6]=14; 
    cur2[1]=54; cur2[2]=53; cur2[3]=49; cur2[4]=48; cur2[5]=46; cur2[6]=55; 
    cur3[1]=64; cur3[2]=66; cur3[3]=65; cur3[4]=69; cur3[5]=68; cur3[6]=36; 
    for(int i=1;i<=6;i++){
        swap(d[cur1[i]],d[cur2[i]]);
    }
    for(int i=1;i<=6;i++){
        swap(d[cur1[i]],d[cur3[i]]);
    }

    // 54->41->37->45

    // 40->44->43->42->38->39->40
}

void opRU(){
    //14 9 8 7 6 5->36 68 69 65 66 64
    //36 68 69 65 66 64->55 46 48 49 53 54
    //55 46 48 49 53 54->14 9 8 7 6 5
    int cur1[7],cur2[7],cur3[7];
    cur1[1]=14; cur1[2]=9; cur1[3]=8; cur1[4]=7; cur1[5]=6; cur1[6]=5; 
    cur2[1]=36; cur2[2]=68; cur2[3]=69; cur2[4]=65; cur2[5]=66; cur2[6]=64; 
    cur3[1]=55; cur3[2]=46; cur3[3]=48; cur3[4]=49; cur3[5]=53; cur3[6]=54; 
    for(int i=1;i<=6;i++){
        swap(d[cur1[i]],d[cur2[i]]);
    }
    for(int i=1;i<=6;i++){
        swap(d[cur1[i]],d[cur3[i]]);
    }

    // 45->37->41->45

    // 40->39->38->42->43->44->40
}

void opF(){
    //10 12 11 15 14 54 -> 41 42 43 44 45 68
    // 41 42 43 44 45 68 ->36 35 31 30 28 19
    //36 35 31 30 28 19->10 12 11 15 14 54
    int cur1[7],cur2[7],cur3[7];
    cur1[1]=10; cur1[2]=12; cur1[3]=11; cur1[4]=15; cur1[5]=14; cur1[6]=54; 
    cur2[1]=41; cur2[2]=42; cur2[3]=43; cur2[4]=44; cur2[5]=45; cur2[6]=68; 
    cur3[1]=36; cur3[2]=35; cur3[3]=31; cur3[4]=30; cur3[5]=28; cur3[6]=19; 
    for(int i=1;i<=6;i++){
        swap(d[cur1[i]],d[cur2[i]]);
    }
    for(int i=1;i<=6;i++){
        swap(d[cur1[i]],d[cur3[i]]);
    }

    //1->9->5->1

    //2->3->4->8->7->6->2
}

void opRF(){
    // 54 14 15 11 12 10->19 28 30 31 35 36
    // 19 28 30 31 35 36->68 45 44 43 42 41
    // 68 45 44 43 42 41->54 14 15 11 12 10

    int cur1[7],cur2[7],cur3[7];
    cur1[1]=54; cur1[2]=14; cur1[3]=15; cur1[4]=11; cur1[5]=12; cur1[6]=10; 
    cur2[1]=19; cur2[2]=28; cur2[3]=30; cur2[4]=31; cur2[5]=35; cur2[6]=36; 
    cur3[1]=68; cur3[2]=45; cur3[3]=44; cur3[4]=43; cur3[5]=42; cur3[6]=41; 
    for(int i=1;i<=6;i++){
        swap(d[cur1[i]],d[cur2[i]]);
    }
    for(int i=1;i<=6;i++){
        swap(d[cur1[i]],d[cur3[i]]);
    }
    //1->5->9->1

    // 2->6->7->8->4->3->2

}

inline void init(){
    flag=false;
}

int main(){
    freopen("in.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        init();
        for(int i=1;i<=8;i++){
            for(int j=1;j<=9;j++){
                scanf("%d",&a[(i-1)*8+j]);
            }
        }
        flag=ok();
        for(int i=1;i<=12;i++){
            if(flag==true) break;
            for(int j=1;j<=12;j++){
                if(flag==true) break;
                if(i==j) continue;
                for(int k=1;k<=12;k++){
                    if(flag==true) break;
                    if(k==j) continue;
                    
                    rec();//恢复数组

                    switch(i){
                        case 1:
                            opR();
                            break;
                        case 2:
                            opL();
                            break;
                        case 3:
                            opML();
                            break;
                        case 4:
                            opMR();
                            break;
                        case 5:
                            opRR();
                            break;
                        case 6:
                            opRL();
                            break;
                        case 7:
                            opRML();
                            break;
                        case 8:
                            opRMR();
                            break;
                        case 9:
                            opU();
                            break;
                        case 10:    
                            opRU();
                            break;  
                        case 11:
                            opF();
                            break;
                        case 12:
                            opRF();
                            break;
                    }
                    if(ok()==true){
                        flag=true;
                        break;
                    }
                    switch(j){
                        case 1:
                            opR();
                            break;
                        case 2:
                            opL();
                            break;
                        case 3:
                            opML();
                            break;
                        case 4:
                            opMR();
                            break;
                        case 5:
                            opRR();
                            break;
                        case 6:
                            opRL();
                            break;
                        case 7:
                            opRML();
                            break;
                        case 8:
                            opRMR();
                            break;
                        case 9:
                            opU();
                            break;
                        case 10:    
                            opRU();
                            break;  
                        case 11:
                            opF();
                            break;
                        case 12:
                            opRF();
                            break;
                    }
                    if(ok()==true){
                        flag=true;
                        break;
                    }

                    switch(k){
                        case 1:
                            opR();
                            break;
                        case 2:
                            opL();
                            break;
                        case 3:
                            opML();
                            break;
                        case 4:
                            opMR();
                            break;
                        case 5:
                            opRR();
                            break;
                        case 6:
                            opRL();
                            break;
                        case 7:
                            opRML();
                            break;
                        case 8:
                            opRMR();
                            break;
                        case 9:
                            opU();
                            break;
                        case 10:    
                            opRU();
                            break;  
                        case 11:
                            opF();
                            break;
                        case 12:
                            opRF();
                            break;
                    }
                    if(ok()==true){
                        flag=true;
                        break;
                    }
                }
            }
        }
        printf(flag==true?"YES\n":"NO");
    }
    return 0;
}