#Criando tarefas FRENTE, DIREITA, ESQUERDA e TRAS

#destrava motor, dps define velocidades para os motores
tarefa Frente com numero velocidade = 100{
	TravarMotor("motorDireita", falso)
	TravarMotor("motorEsquerda", falso)
	Motor("motorDireita", velocidade)
	Motor("motorEsquerda", velocidade)
}


#trava motor direita, dps define velocidade para o motor esquerda
tarefa Direita com numero velocidade = 100{
	TravarMotor("motorDireita", verdadeiro)
	TravarMotor("motorEsquerda", falso)
	Motor("motorEsquerda", velocidade)
}

#trava motor esquerda, dps define velocidade para o motor direita
tarefa Esquerda com numero velocidade = 100{
	TravarMotor("motorDireita", falso)
	TravarMotor("motorEsquerda", verdadeiro)
	Motor("motorDireita", velocidade)
}

#destrava os motores, dps define velocidades negativas para ambos
tarefa Tras com numero velocidade = 100{
	TravarMotor("motorDireita", falso)
	TravarMotor("motorEsquerda", falso)
	Motor("motorDireita", 0-velocidade)
	Motor("motorEsquerda", 0-velocidade)
}

numero contador = 0
tarefa ledFinal{
	para contador de 1 ate 5 passo 1 farei {
		LigarLuz("led",0,255,255)
		Esperar(80)
		LigarLuz("led",255,0,0)
		Esperar(80)
		LigarLuz("led",0,0,255)
		Esperar(80)
	}
}


inicio

	enquanto(verdadeiro) farei{
		Esperar(50)	#Importante para evitar a quebra no Simulador

	
		se(Cor("sensorEsquerda")=="Verde") entao {
			LigarLuz("ledE",0,255,0)
			LigarLuz("ledD",255,255,255)
			
			enquanto(Cor("sensorEsquerda") != "Preto") farei{
				Esperar(50)
				Frente()
			}

			enquanto(Cor("sensorDireita") != "Preto") farei{
				Esperar(50)
				Esquerda(300)
			}
			Esperar(500)
			Esquerda(300)
			
		} senao se((Cor("sensorDireita")=="Preto") e (Cor("sensorEsquerda")=="Branco")) entao {
			LigarLuz("ledE",255,255,255)
			LigarLuz("ledD",0,0,0)
			Direita(300)

		} senao se((Cor("sensorDireita")=="Branco") e (Cor("sensorEsquerda")=="Preto")) entao {
				LigarLuz("ledD",255,255,255)
				LigarLuz("ledE",0,0,0)
				Esquerda(300)

		} senao se ((Cor("sensorDireita")=="Preto") e (Cor("sensorEsquerda")=="Preto")) entao {
			LigarLuz("ledE",0,0,0)
			LigarLuz("ledD",0,0,0)
			Frente()

		} senao se((Cor("sensorDireita")=="Vermelho") ou (Cor("sensorEsquerda")=="Vermelho")) entao{
				
			Frente(0)				
		} senao {
			LigarLuz("ledE",255,255,255)
			LigarLuz("ledD",255,255,255)
			Frente()
		}	
	}

fim