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


inicio
	LigarLuz("led",255,0,255)
	enquanto(verdadeiro) farei{
		Esperar(50)	#Importante para evitar a quebra no Simulador

		Frente()
	
		Escrever(Cor("sensorDireita"))		
	}

fim