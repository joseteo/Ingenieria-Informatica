package factoria;

public class factoriaMalaga extends FactoriaMalagaGranada{
    @Override
        public Procesion crearProcesion(){
            return new ProcesionMalaga();
        }
    @Override
        public Costalero crearCostalero(){
            return new CostaleroMalaga();
        }
}
