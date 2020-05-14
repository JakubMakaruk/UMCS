public class Main {
    public static void main(String[] args) {
        String wyrazenie = "100 1 - 20 +"; // wyrazenie w POSTFIX - infix=100-1+20
        Kalkulator kalkulator = new Kalkulator(wyrazenie);
        kalkulator.oblicz(); // wynik: 119
    }
}


