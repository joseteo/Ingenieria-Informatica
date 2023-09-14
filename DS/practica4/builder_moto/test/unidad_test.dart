import 'package:flutter_test/flutter_test.dart';
import 'package:flutter/material.dart';
import 'package:test_flutter/Asiento.dart';
import 'package:test_flutter/Builder.dart';
import 'package:test_flutter/Chasis.dart';
import 'package:test_flutter/Director.dart';
import 'package:test_flutter/Electronica.dart';
import 'package:test_flutter/Moto.dart';
import 'package:test_flutter/MotoBuilder.dart';
import 'package:test_flutter/Motor.dart';
import 'package:test_flutter/TipoFrenos.dart';
import 'package:test_flutter/TipoMoto.dart';
import 'package:test_flutter/TipoSuspension.dart';
import 'package:test_flutter/TrenRodaje.dart';


void main()
{


  group('Moto',(){

    MotoBuilder builder = MotoBuilder(
        TipoMoto.MOTODEPORTIVA,
        Chasis.MONOCASCO,
        Asiento.ASIENTOROJO,
        Motor(TipoMoto.MOTODEPORTIVA),
        TrenRodaje(17, TipoFrenos.DISCO, TipoSuspension.DURA),
        Electronica(true, false, true, true)
    );
    Moto moto = builder.entregaMoto();

    test('Se crea una moto y se comprueba el tipo', (){
      expect(moto.tipoMoto, TipoMoto.MOTODEPORTIVA);
    });

    test('Se cambia el tipo de  una moto y se comprueba el tipo', (){
      moto.tipoMoto = TipoMoto.MOTOSCOOTER;
      expect(moto.tipoMoto, TipoMoto.MOTOSCOOTER);
    });
  });


  group('Electronica',(){
    Electronica electronica = Electronica(true, false, true, true) ;
    test('Se crea una electronica y se comprueba el abs', (){

      expect(electronica.abs, true);
    });

    test('Se cambia la electronica y se comprueba el estado', (){
      electronica.abs = false;
      expect(electronica.abs, false);
    });
  });


  group('TrenRodaje',(){
    TrenRodaje tren = TrenRodaje(17, TipoFrenos.DISCO, TipoSuspension.DURA);
    test('Se crea un tren rodaje y se comprueba ', (){

      expect(tren.pulgadaRueda, 17);
      expect(tren.tipoFrenos, TipoFrenos.DISCO);
      expect(tren.tipoSuspension, TipoSuspension.DURA);
    });

    test('Se cambian las pulgadas de la rueda y se comprueba el estado', (){
      TrenRodaje tren2 = TrenRodaje(21, TipoFrenos.TAMBOR, TipoSuspension.BLANDA);
      tren = tren2;

      expect(tren.pulgadaRueda, 21);
      expect(tren.tipoFrenos, TipoFrenos.TAMBOR);
      expect(tren.tipoSuspension, TipoSuspension.BLANDA);
    });
  });

}