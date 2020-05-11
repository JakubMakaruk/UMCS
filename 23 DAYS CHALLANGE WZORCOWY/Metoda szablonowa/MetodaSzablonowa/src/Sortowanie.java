public abstract class Sortowanie {
    private int [] tablica;

    public Sortowanie(int arr []) {
        tablica = arr;
    }

    public void wyswietl() {
        for(int i : tablica)
            System.out.println(i);
    }

    public void sortowanie() {
        for(int i=1; i<tablica.length; i++) {
            int k = tablica[i];
            int j = i-1;
            while(j>=0 && porownaj(tablica[j], k)) {
                tablica[j+1] = tablica[j];
                j=j-1;
            }
            tablica[j+1]=k;
        }
    }

    public abstract boolean porownaj(int a, int b);
}

