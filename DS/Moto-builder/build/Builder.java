package build ;


public interface Builder {
    void setMotoTipo(MotoTipo tipo);
    void setChasis(Chasis chasis);
    void setAsientos(Asiento asiento);
    void setMotor(Motor motor);
    void setTrenRodaje(TrenRodaje trenRodaje);
    void setElectronica(Electronica electronica);
}
