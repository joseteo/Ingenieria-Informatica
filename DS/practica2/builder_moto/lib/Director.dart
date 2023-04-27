import 'package:test_flutter/MotoBuilder.dart';
import 'package:test_flutter/Moto.dart';

// Clase que define al Director que controla la construcción de la moto
class MotoDirector {
  MotoBuilder builder;

  MotoDirector({required this.builder});

  // Método para definir el builder que se usará para construir la moto
  setMotoBuilder(MotoBuilder builder) {
    this.builder = builder;
  }

  // Método que utiliza el builder para construir la moto
  Moto buildMoto() {
    builder.setAsientos();
    builder.setChasis();
    builder.setMotor();
    builder.setElectronica();
    builder.setTrenRodaje();
    builder.setMotoTipo();

    return builder.entregaMoto();
  }
}
