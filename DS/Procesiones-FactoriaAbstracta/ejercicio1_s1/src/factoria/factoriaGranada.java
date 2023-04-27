package factoria;

public class factoriaGranada extends FactoriaMalagaGranada{
    @Override
        public Procesion crearProcesion(){
            return new ProcesionGranada();
        }
    @Override
        public Costalero crearCostalero(){
            return new CostaleroGranada();
        }
}
