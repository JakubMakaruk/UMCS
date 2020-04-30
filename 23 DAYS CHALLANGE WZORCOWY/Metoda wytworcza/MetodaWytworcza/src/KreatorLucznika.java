public class KreatorLucznika implements KreatorPostaci {
    public KreatorLucznika() {
    }

    @Override
    public Postac stworz() {
        return new Lucznik();
    }
}