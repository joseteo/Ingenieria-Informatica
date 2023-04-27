
package civitas;
public class JugadorEspeculador extends Jugador {
    private static int FactorEspeculador = 2;
    private float fianza;
    private Boolean especulador;
    
    JugadorEspeculador(Jugador jugador, float fianza){
        super(jugador);
        this.fianza = fianza;
        especulador = true;
        for (int i = 0; i < super.getPropiedades().size(); i++){
            super.getPropiedades().get(i).actualizaPropietarioPorConversion(this);
        }
    }
    
    @Override
    Boolean encarcelar(int numCasillaCarcel){
        Boolean resultado = false;
        if (!super.encarcelado){
            if (!super.tieneSalvoconducto()){
                if (fianza >= super.getSaldo()){
                    resultado = true;
                } else {
                    super.paga(fianza);
                    Diario.getInstance().ocurreEvento("El jugador "+super.getNombre()+" Se ha librado de la carcel paganzo una fianza");
                }
            } else {
                resultado = false;
                super.perderSalvoconducto();
                Diario.getInstance().ocurreEvento("El jugador "+super.getNombre()+" se libra de la carcel");
            }
        }
        return resultado;
    }
    
    @Override
    int getHotelesMax(){
        return (super.getHotelesMax() * FactorEspeculador );
    }
    
    @Override
    int getCasasMax(){
        return (super.getCasasMax() * FactorEspeculador );
    }
    
    @Override
    Boolean pagaImpuesto(float cantidad){
        Boolean resultado = false;
        if (!encarcelado){
            float impuesto = cantidad / 2;
            resultado = paga(impuesto);
            Diario.getInstance().ocurreEvento("El jugador "+super.getNombre()+" paga "+impuesto+" euros por impuesto");
        }
        return resultado;
    }
    
    @Override
    public String toString(){
        return "Jugador{ nombre=" + super.getNombre() + ", encarcelado=" + Boolean.toString(super.isEncarcelado()) +  ", numCasillaActual=" + super.getNumCasillaActual() + ", puedeComprar=" + super.getPuedeComprar() +
                ", saldo=" + super.getSaldo() + ", especulador=" + Boolean.toString(especulador) + "}";
    }
}
