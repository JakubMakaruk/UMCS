public class KreatorTopornika implements KreatorPostaci {

    public KreatorTopornika() {
    }

    @Override
    public Postac stworz() {
        return new Topornik();
    }
}