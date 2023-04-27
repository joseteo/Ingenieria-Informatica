enum TipoFrenos { DISCO, TAMBOR }

extension ParseToString on TipoFrenos {
  String toShortString() {
    switch (this) {
      case TipoFrenos.DISCO:
        return "Disco";
      case TipoFrenos.TAMBOR:
        return "Tambor";
      default:
        return "Sin tipo de frenos";
    }
  }
}
