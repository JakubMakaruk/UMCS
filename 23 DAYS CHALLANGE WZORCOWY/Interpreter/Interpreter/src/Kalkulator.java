import java.util.Stack;

public class Kalkulator {
    public Wyrazenie [] tablica = new Wyrazenie[50];
    int index=0;

    public Kalkulator(String wyraz) {
        for(int i=0; i<50; i++)
            tablica[i] = null;

        for(String i : wyraz.split(" ")) {
            if(i.equals("+"))
                tablica[index] = new Plus();
            else if(i.equals("-"))
                tablica[index] = new Minus();
            else {
                int temp = Integer.parseInt(i);
                tablica[index] = new Liczba(temp);
            }
            index++;
        }
    }

    public void oblicz() {
        Stack<Integer> pomocniczyStos = new Stack<Integer>();
        for(Wyrazenie i : tablica) {
            if(i!=null)
                i.interpretuj(pomocniczyStos);
        }
        System.out.println("Wynik: " + pomocniczyStos.pop());
    }
}

