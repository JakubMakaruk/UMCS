public class Main {
    public static void main(String[] args) {
        Lancuch klientA = new KlientA("Adam Kowalski"); // stan konta = 200
        Lancuch klientB = new KlientB("Jan Nowak"); // stan konta = 500
        Lancuch klientC = new KlientC("Zenon Martyniuk"); // stan konta = 1000

        klientA.setNext(klientB); // if klientA==NIE else if -> klientB
        klientB.setNext(klientC); // if klientB==NIE else if -> klientC

        Zamowienie zamowienie1 = new Zamowienie(1, 600, "Zakup komputera");
        klientA.autoryzacja(zamowienie1); // powinien kupic KlientC(Zenon Martyniuk), bo ma ponad 600 pieniedzy.

        Zamowienie zamowienie2 = new Zamowienie(2, 100, "Zakup sprzetu audio");
        klientA.autoryzacja(zamowienie2); // powinien kupic KlientA(Adam Kowalski), bo jest pierwszy w łańcuchu ifów i jego stan konta pozwala na zakup.

        Zamowienie zamowienie3 = new Zamowienie(3, 400, "Zakup monitora");
        klientA.autoryzacja(zamowienie3); // powinien kupic KlientB(Jan Nowak), bo pierwszy if przekieruje do else ifa
    }
}


