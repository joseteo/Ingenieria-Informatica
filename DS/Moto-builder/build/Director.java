package build;

public class Director {
    public void constructorMotoDeportiva(Builder builder) {
        builder.setMotoTipo(MotoTipo.MOTODEPORTIVA);
        builder.setAsientos(Asiento.ASIENTOROJO);
        builder.setChasis(Chasis.DOBLEVIGAPERIMETRAL);
        builder.setTrenRodaje(new TrenRodaje(TipoSuspension.DURA, 17, TipoFrenos.DISCO));
        builder.setMotor(new Motor(100, 650, 10000, true));
        builder.setElectronica(new Electronica(true, false, true, true));
    }

    public void constructorMotoScooter(Builder builder) {
        builder.setMotoTipo(MotoTipo.MOTOSCOOTER);
        builder.setAsientos(Asiento.ASIENTOBLANCO);
        builder.setChasis(Chasis.MULTITUBULAR);
        builder.setTrenRodaje(new TrenRodaje(TipoSuspension.BLANDA, 14, TipoFrenos.TAMBOR));
        builder.setMotor(new Motor(15, 125, 50000, true));
        builder.setElectronica(new Electronica(true, false, false, true));
    }

    public void constructorMotoTouring(Builder builder) {
        builder.setMotoTipo(MotoTipo.MOTOTOURING);
        builder.setAsientos(Asiento.ASIENTOROJO);
        builder.setChasis(Chasis.SIMPLECUNADESDOBLADO);
        builder.setTrenRodaje(new TrenRodaje(TipoSuspension.MEDIA, 20, TipoFrenos.DISCO));
        builder.setMotor(new Motor(150, 1200, 25000, true));
        builder.setElectronica(new Electronica(true, true, true, true));
    }
}
