enum TipoMoto { MOTODEPORTIVA, MOTOSCOOTER, MOTOTOURING }

extension ParseToString on TipoMoto {
  String toShortString() {
    switch (this) {
      case TipoMoto.MOTODEPORTIVA:
        return "Deportiva";
      case TipoMoto.MOTOSCOOTER:
        return "Scooter";
      case TipoMoto.MOTOTOURING:
        return "Touring";
      default:
        return "Sin tipo de moto";
    }
  }
}
