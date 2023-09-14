class Electronica {
  bool _abs;
  bool _controlCrucero;
  bool _controlTraccion;
  bool _repartoFrenada;

  Electronica(
    this._abs,
    this._controlCrucero,
    this._controlTraccion,
    this._repartoFrenada,
  );

  bool get abs {
    return _abs;
  }

  bool get controlCrucero {
    return _controlCrucero;
  }

  bool get controlTraccion {
    return _controlTraccion;
  }

  bool get repartoFrenada {
    return _repartoFrenada;
  }

  set abs (bool abs) {
    _abs = abs;
  }

  set controlCrucero (bool controlCrucero) {
    _controlCrucero = controlCrucero;
  }

  set controlTraccion (bool controlTraccion) {
    _controlTraccion = controlTraccion;
  }

  set repartoFrenada (bool repartoFrenada) {
    _repartoFrenada = repartoFrenada;
  }


}