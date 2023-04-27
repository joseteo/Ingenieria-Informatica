package build;

public class TrenRodaje {
   private TipoSuspension tipoSuspension;
   private int pulgadaRueda;
   private TipoFrenos tipoFrenos;

   public TrenRodaje(TipoSuspension tipoSuspension, int pulgadaRueda, TipoFrenos tipoFrenos){
        this.tipoSuspension = tipoSuspension;
        this.pulgadaRueda = pulgadaRueda;
        this.tipoFrenos = tipoFrenos;

    }


    public int getPulgadaRueda() {
        return pulgadaRueda;
    }
    public TipoFrenos getTipoFrenos() {
        return tipoFrenos;
    }
    public TipoSuspension getTipoSuspension() {
        return tipoSuspension;
    }

}
