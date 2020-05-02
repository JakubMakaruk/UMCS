public class FabrykaOpel implements FabrykaAbstrakcyjna {
    @Override
    public Samochod stworzSamochod() {
        return new SamochodOpel();
    }

    @Override
    public Kluczyki stworzKluczyki() {
        return new KluczykiOpel();
    }
}