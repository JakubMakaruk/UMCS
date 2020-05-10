public class Main {
    public static void main(String[] args) {
        Caretaker obslugaStanow = new Caretaker();
        Originator edytorTekstowy = new Originator();

        edytorTekstowy.setStan("Ala ma kota");
        System.out.println(edytorTekstowy.getObecnyStan()); // Ala ma kota
        obslugaStanow.dodajStan(edytorTekstowy.save());

        edytorTekstowy.setStan("Kacper to kozak");
        System.out.println(edytorTekstowy.getObecnyStan()); // Kacper to kozak

        edytorTekstowy.cofnij(obslugaStanow.getStan());
        System.out.println(edytorTekstowy.getObecnyStan()); // Ala ma kota - cofnięto zmiany
    }
}



