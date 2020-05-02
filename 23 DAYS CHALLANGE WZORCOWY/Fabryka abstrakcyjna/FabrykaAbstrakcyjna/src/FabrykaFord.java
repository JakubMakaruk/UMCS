public class FabrykaFord implements FabrykaAbstrakcyjna {
    @Override
    public Samochod stworzSamochod() {
        return new SamochodFord();
    }

    @Override
    public Kluczyki stworzKluczyki() {
        return new KluczykiFord();
    }
}