inicio
	TravarMotor("motorFrenteEsq", falso)
	TravarMotor("motorFrenteDir", falso)
    TravarMotor("motorTrasEsq", falso)
	TravarMotor("motorTrasDir", falso)	
 

	enquanto(verdadeiro) farei {
	
		#indo para frente
		DefinirMotor("motorFrenteEsq",400, 200)
		DefinirMotor("motorFrenteDir",400, 200)
		DefinirMotor("motorTrasEsq",400, 200)
		DefinirMotor("motorTrasDir",400, 200)		

		se(Cor("sensorCorDir")=="Preto" ou Cor("sensorCorDirExt")=="Preto") entao{
			#virando para a direita
			DefinirMotor("motorFrenteEsq",100, 200)
			DefinirMotor("motorFrenteDir",100, 0-200)
			DefinirMotor("motorTrasEsq",100, 200)
			DefinirMotor("motorTrasDir",100, 0-200)
		}

		senao se(Cor("sensorCorEsq")=="Preto" ou Cor("sensorCorEsqExt")=="Preto") entao{
			DefinirMotor("motorFrenteEsq",100, 0-200)
			DefinirMotor("motorFrenteDir",100, 200)
			DefinirMotor("motorTrasEsq",100, 0-200)
			DefinirMotor("motorTrasDir",100, 200)
		}

		Esperar(1)
	}

fim