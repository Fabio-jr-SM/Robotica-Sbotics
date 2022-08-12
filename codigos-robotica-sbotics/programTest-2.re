tarefa Frente com numero velocidade = 100{
    Motor("me",velocidade)
    Motor("md",velocidade)
    }
    
    tarefa Esquerda com numero velocidade = 100{
    Motor("me",velocidade)
    Motor("md",0-velocidade)
    }
    
    tarefa Direita com numero velocidade = 100{
    Motor("me",velocidade)
    Motor("md",0-velocidade)
    }
    
    
    inicio
    
    TravarMotor("me", verdadeiro)
    TravarMotor("md", verdadeiro)
    
    enquanto(verdadeiro) farei{
    Esperar(50)
    }
    fim