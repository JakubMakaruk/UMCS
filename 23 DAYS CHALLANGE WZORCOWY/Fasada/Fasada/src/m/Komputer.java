package m;
import m.pc.*;

public class Komputer {
    private Procesor cpu;
    private KartaGraficzna gpu;
    private DyskTwardy disk1;
    private PamiecRAM ram1;

    public Komputer() {
        cpu = new Procesor();
        gpu = new KartaGraficzna();
        disk1 = new DyskTwardy();
        ram1 = new PamiecRAM();
    }

    public void uruchom() {
        cpu.pobierzDane();
        gpu.zaladuj();
        disk1.wczytajDane();
        ram1.zaladuj();

        System.out.println("\nKOMPUTER URUCHOMIONY\n");

        gpu.renderuj();
        gpu.konwersja();
    }
}