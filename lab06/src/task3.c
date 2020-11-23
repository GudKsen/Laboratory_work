int main(){
    #define STR 4
    #define TH 15
    #define HN 14
    #define DEC 8
    #define TEN 10
    #define SN 5
    int a = TH, b = HN, c = DEC, d = TEN, e = SN; 
    
    char thousand[9][TH] = {{'O','n','e',' ','t','h','o','u','s','a','n','d'},
                         {'T','w','o',' ','t','h','o','u','s','a','n','d'},
                         {'T','h','r','e','e',' ','t','h','o','u','s','a','n','d'},
                         {'F','o','u','r',' ','t','h','o','u','s','a','n','d'},
                         {'F','i','v','e',' ','t','h','o','u','s','a','n','d'},
                         {'S','i','x',' ','t','h','o','u','s','a','n','d'},
                         {'S','e','v','e','n',' ','t','h','o','u','s','a','n','d'},
                         {'E','i','g','h','t',' ','t','h','o','u','s','a','n','d'},
                         {'N','i','n','e',' ','t','h','o','u','s','a','n','d'}};
    char hundred[9][HN] = {{'O','n','e',' ','h','u','n','d','r','e','d'},
                        {'T','w','o',' ','h','u','n','d','r','e','d'},
                        {'t','h','r','e','e',' ','h','u','n','d','r','e','d'},
                        {'f','o','u','r',' ','h','u','n','d','r','e','d'},
                        {'f','i','v','e',' ','h','u','n','d','r','e','d'},
                        {'s','i','x',' ','h','u','n','d','r','e','d'},
                        {'s','e','v','e','n',' ','h','u','n','d','r','e','d'},
                        {'e','i','g','h','t',' ','h','u','n','d','r','e','d'},
                        {'n','i','n','e',' ','h','u','n','d','r','e','d'}};
    char dec[9][DEC] = {{'t','w','e','n','t','y'},
                    {'t','h','i','r','t','y'},
                    {'f','o','u','r','t','y'},
                    {'f','i','f','t','y'},
                    {'s','i','x','t','y'},
                    {'s','e','v','e','n','t','y'},
                    {'e','i','g','h','t','y'},
                    {'n','i','n','e','t','y'}};
    char ten[9][TEN] = {{'t','e','n'},
                    {'e','l','e','v','e','n'},
                    {'t','w','e','l','v','e'},
                    {'t','h','i','r','t','e','e','n'},
                    {'f','o','u','r','t','e','e','n'},
                    {'f','i','f','t','e','e','n'},
                    {'s','i','x','t','e','e','n'},
                    {'s','e','v','e','n','t','e','e','n'},
                    {'e','i','g','h','t','e','e','n'},
                    {'n','i','n','e','t','e','e','n'}};
    char single[9][SN] = {{'o','n','e'},
                       {'t','w','o'},
                       {'t','h','r','e','e'},
                       {'f','o','u','r'},
                       {'f','i','v','e'},
                       {'s','i','x'},
                       {'s','e','v','e','n'},
                       {'e','i','g','h','t'},
                       {'n','i','n','e'}};

    #define NUMBER 4321
    int first = NUMBER / 1000;
    int second = (NUMBER % 1000) / 100;
    int third = ((NUMBER % 1000) % 100) / 10;
    int fourth = ((NUMBER % 1000) % 100) % 10;
    char arr[4][15];
    if(first > 0){                                  //визначення тисяч
        for(int i = 0; i < TH; i++){
            arr[0][i] = thousand[first - 1][i];
        }
    }
    if(second > 0){                                //визначення сотень
        for(int i = 0; i < HN; i++){
            arr[1][i] = hundred[second - 1][i];
        }
    }
    if(third > 1){                                 //визначення десятків
        for(int i = 0; i < DEC; i++){
            arr[2][i] = dec[third - 1][i];
        }
        if(fourth > 0){                            //визначення одиниць
            for(int i = 0; i < SN; i++){
                arr[3][i] = single[fourth - 1][i];
            }
        }    
    }
    if(third == 1){                                // 10-19
        for(int i = 0; i < TEN; i++){
            arr[2][i] = ten[fourth - 1][i];
        }
    }

    char result[60] = {0};                       
    int k = 0;
   for(int i = 0; i < 4; i++){                    //результуючий масив
       for(int j = 0; j < 15; j++){
           result[k] = arr[i][j];
           k++;
       }
   }


return 0;
}