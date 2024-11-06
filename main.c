#include <stdio.h>
#include <string.h>

//nama acara
int validasiacara (char *acara){
    int jumlahkata = 0;
    for(int i = 0; i < strlen(acara); i++){
        if(acara[i] == ' ' && acara[i+1] != ' '){
            jumlahkata++;
        }
    }
    jumlahkata++;
    return jumlahkata >= 3 && jumlahkata <= 10;
}

//nama peserta
int validasipeserta (char *peserta){
    int jumlahpeserta = 0;
    for (int i = 0; i < strlen(peserta); i++) {
        if (peserta[i] == ',') {
            jumlahpeserta++;
        }
    }
    return jumlahpeserta <= 2;
}

//instansi
//email
int validasiemail (char *email){
    return strstr(email, "@") != NULL && (strstr(email, ".ac.id") != NULL || strstr(email, ".edu") != NULL);
}

//abstrak
int validasiabstrak (char *abstrak){
    int jumlahkata = 1;
    for (int i = 0; i < strlen(abstrak); i++) {
        if (abstrak[i] == ' ' && abstrak[i+1] != ' ') {
            jumlahkata++;
        }
    }
    jumlahkata++;
    return jumlahkata <= 150;
}

//kata kunci
int validasikatakunci (char *kunci){
    int katakunci = 0;
    for (int i = 0; i < strlen(kunci); i++) {
        if (kunci[i] == ',') {
            katakunci++;
        }
    }
    katakunci++;
    return katakunci >= 2 && katakunci <= 4;
}

//fungsi buat input
void getinput(char *prompt, char *input, int size){
    printf("%s", prompt);
    fgets(input, size, stdin);
    input[strcspn(input, "\n")] = '\0';
}

//inputan
void karyailmiah() {
    char acara[150], peserta[100], instansi[100], email[50], abstrak[1500], kunci[100];
    //input
    //judul
    do {
        getinput("judul acara (3-10 kata) : ", acara, sizeof(acara));
        if(!validasiacara(acara)){
            printf("nama tidak valid! Judul harus terdiri dari 3 hingga 14 kata. Coba lagi.\n");
        }
    } while (!validasiacara(acara));
    
    //penulis
    do {
        getinput("masukan nama peserta (maksimal 2 orang dan dipisahkan dengan koma',') : ", peserta, sizeof(peserta));
        if (!validasipeserta(peserta)) {
            printf("maksimal peserta 2 orang dan tiap nama dipisahkan dengan koma','\n");
        }
    } while (!validasipeserta(peserta));
    
    //instansi
    getinput("masukan Instansi : ", instansi, sizeof(instansi));
    
    //email
    do {
        getinput("masukan email (gunakan email dengan domain '.edu' atau '.ac.di') : ", email, sizeof(email));
        if (!validasiemail(email)) {
            printf("email tidak valid! Coba lagi.\n");
        }
    } while (!validasiemail(email));
    
    //abstrak
    do {
        getinput("masukan abtrak (max 150 kata) : ", abstrak, sizeof(abstrak));
        if (!validasiabstrak(abstrak)) {
            printf("abstrak melebihi maksimal kata. coba lagi\n");
        }
    } while (!validasiabstrak(abstrak));
    
    //kata kunci
    do {
        getinput("masukan kata kunci (2-4 kata, dipisahkan dengan koma',') : ", kunci, sizeof(kunci));
        if (!validasikatakunci(kunci)) {
            printf("kata kunci harus terdiri dari 2 hingga 4 kata dan dipisahkan dengan koma ','.\n");
        }
    } while (!validasikatakunci(kunci));
    
    //hasil
    printf("\n==================== Journal ====================\n");
    printf("Judul : %s\n", acara);
    printf("Penulis : %s\n", peserta);
    printf("Instansi : %s\n", instansi);
    printf("Email : %s\n", email);
    printf("Abstrak : %s\n", abstrak);
    printf("Kata kunci : %s\n", kunci);
}

int main() {
    karyailmiah();
    return 0;
}
