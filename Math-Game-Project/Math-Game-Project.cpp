#include <iostream> 
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;


enum enQuestionLevel { EasyLevel = 1, MedLevel = 2, HardLevel = 3, Mix = 4 };

enum enOperationType { Add = 1, Sub = 2, Mult = 3, Div = 4, MixOp = 5 };


struct stQuestion
{
	int Number1 = 0;
	int Number2 = 0;
	enQuestionLevel QuestionLevel;
	enOperationType OperationType;
	short PlayerAnswer = 0;
	short CorrectAnswer = 0;
	bool AnswerRight = false;
};


struct stQuiz
{
	stQuestion QuestionsList[100];
	short NumberOfQuestion = 0;
	enQuestionLevel QuestionLevel;
	enOperationType OperationType;
	short NumberOfRightAnswers = 0;
	short NumberOfWrongAnswers = 0;
	bool IsPass = false;
};


char GetOperationTypeSympol(enOperationType OperationType)
{
	switch (OperationType)
	{
	case enOperationType::Add:
		return '+';

	case enOperationType::Sub:
		return '-';

	case enOperationType::Mult:
		return '*';

	case enOperationType::Div:
		return '/';
	}
}

int RandomNumbers(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}


short ReadHowManyQuestionsNumber()
{
	short NumberOfQuestions = 0;

	do
	{
		cout << "Please Enter Questions Of Number Between 1 and 10 : ";
		cin >> NumberOfQuestions;

	} while (NumberOfQuestions < 1 || NumberOfQuestions > 10);


	return NumberOfQuestions;
}


enQuestionLevel ReadQuestionLevel()
{
	short QuestionLevel = 0;

	do
	{
		cout << "Please Enter Question Level: [1] Easy Level [2] Med Level [3] Hard Level [4] Mix : ";
		cin >> QuestionLevel;

	} while (QuestionLevel < 1 || QuestionLevel > 4);


	return (enQuestionLevel)QuestionLevel;
}

enOperationType ReadOperationType()
{
	short OperationType = 0;

	do
	{
		cout << "Please Enter Operation Type: [1] Add [2] Sub [3] Mult [4] Div [5] Mix : ";
		cin >> OperationType;

	} while (OperationType < 1 || OperationType > 5);


	return (enOperationType)OperationType;
}

int SimpleCalculater(int Number1, int Number2, enOperationType OperationType)
{
	switch (OperationType)
	{
	case enOperationType::Add:
		return Number1 + Number2;

	case enOperationType::Sub:
		return Number1 - Number2;

	case enOperationType::Mult:
		return Number1 * Number2;

	case enOperationType::Div:
		return Number1 / Number2;

	default:
		return Number1 + Number2;
	}
}


string PrintQuestionText(enQuestionLevel QuestionLevel)
{
	string arrQuestionLevel[4] = { "Easy Level", "Med Level", "Hard Level", "Mix" };

	return arrQuestionLevel[QuestionLevel - 1];
}


string PrintOperationText(enOperationType OperationType)
{
	string arrOperationType[5] = { "Add", "Sub", "Mult" , "Div", "Mix" };

	return arrOperationType[OperationType - 1];
}




enOperationType GetOperationRandom()
{
	int OperationType = RandomNumbers(1, 4);

	return (enOperationType)OperationType;
}


stQuestion GenerateQuestion(enQuestionLevel QuestionLevel, enOperationType OperationType)
{
	stQuestion Question;

	if (QuestionLevel == enQuestionLevel::Mix)
	{
		QuestionLevel = (enQuestionLevel)RandomNumbers(1, 3);
	}

	if (OperationType == enOperationType::MixOp)
	{
		OperationType = GetOperationRandom();
	}

	Question.OperationType = OperationType;

	switch (QuestionLevel)
	{
	case enQuestionLevel::EasyLevel:
	{
		Question.Number1 = RandomNumbers(1, 10);
		Question.Number2 = RandomNumbers(1, 10);

		Question.CorrectAnswer = SimpleCalculater(Question.Number1, Question.Number2, OperationType);
		return Question;
	}

	case enQuestionLevel::MedLevel:
	{
		Question.Number1 = RandomNumbers(10, 50);
		Question.Number2 = RandomNumbers(10, 50);

		Question.CorrectAnswer = SimpleCalculater(Question.Number1, Question.Number2, OperationType);
		return Question;
	}

	case enQuestionLevel::HardLevel:
	{
		Question.Number1 = RandomNumbers(50, 100);
		Question.Number2 = RandomNumbers(50, 100);

		Question.CorrectAnswer = SimpleCalculater(Question.Number1, Question.Number2, OperationType);
		return Question;
	}

	}

	return Question;
}

void GenerateQuizQuestions(stQuiz& Quiz)
{
	for (int QuestionNumber = 0; QuestionNumber < Quiz.NumberOfQuestion; QuestionNumber++)
	{
		Quiz.QuestionsList[QuestionNumber] = GenerateQuestion(Quiz.QuestionLevel, Quiz.OperationType);
	}
}

short ReadPlayerAnswer()
{
	short PlayerAnswer = 0;
	cin >> PlayerAnswer;
	return PlayerAnswer;
}


void PrintTheQuestion(stQuiz& Quiz, short NumberOfQuestions)
{
	cout << "\n";
	cout << "Question [" << NumberOfQuestions + 1 << "/" << Quiz.NumberOfQuestion << "]" << endl;
	cout << Quiz.QuestionsList[NumberOfQuestions].Number1 << endl;
	cout << Quiz.QuestionsList[NumberOfQuestions].Number2 << " ";
	cout << GetOperationTypeSympol(Quiz.QuestionsList[NumberOfQuestions].OperationType) << endl;
	cout << "\n_______________" << endl;
}


void SetScreenColor(bool Right)
{
	if (Right)
		system("color 2F"); // Green for correct answers.
	else
	{
		system("color 4F"); // Red for incorrect answers.
		cout << "\a"; // Plays an alert sound.
	}
}


void CorrectTheQuestionAnswer(stQuiz& Quiz, short NumberOfQuestions)
{
	if (Quiz.QuestionsList[NumberOfQuestions].PlayerAnswer != Quiz.QuestionsList[NumberOfQuestions].CorrectAnswer)
	{
		Quiz.QuestionsList[NumberOfQuestions].AnswerRight = false;
		Quiz.NumberOfWrongAnswers++;

		cout << "Wrong Answer :-( \n";
		cout << "The Right Answer Is: " <<
			Quiz.QuestionsList[NumberOfQuestions].CorrectAnswer;
		cout << endl;
	}
	else
	{
		Quiz.QuestionsList[NumberOfQuestions].AnswerRight = true;
		Quiz.NumberOfRightAnswers++;

		cout << "Right Answer :-) " << endl;
	}

	SetScreenColor(Quiz.QuestionsList[NumberOfQuestions].AnswerRight);
}

void AskAndCorrectQuestonListAnswer(stQuiz& Quiz)
{
	for (int QuestionNumber = 0; QuestionNumber < Quiz.NumberOfQuestion; QuestionNumber++)
	{
		PrintTheQuestion(Quiz, QuestionNumber);

		Quiz.QuestionsList[QuestionNumber].PlayerAnswer = ReadPlayerAnswer();

		CorrectTheQuestionAnswer(Quiz, QuestionNumber);
	}

	Quiz.IsPass = (Quiz.NumberOfRightAnswers >= Quiz.NumberOfWrongAnswers);
}


string GetFinalResultText(bool Pass)
{
	if (Pass == true)
		return "PASS :-)";
	else
		return "FAIL :-(";
}

void PritTheFinalQuiz(stQuiz Quiz)
{
	cout << "\n";
	cout << "____________________________\n\n";
	cout << "Final Results " << GetFinalResultText(Quiz.IsPass) << endl;
	cout << "____________________________\n\n\n";

	cout << "Number Of Questions      : " << Quiz.NumberOfQuestion << endl;
	cout << "Questions Level          : " << PrintQuestionText(Quiz.QuestionLevel) << endl;
	cout << "Operation Type           : " << PrintOperationText(Quiz.OperationType) << endl;
	cout << "Number Of Rigth Answers  : " << Quiz.NumberOfRightAnswers << endl;
	cout << "Number Of Wrong Answers  : " << Quiz.NumberOfWrongAnswers << endl;
	cout << "____________________________" << endl;
}

void PlayMathGame()
{
	stQuiz Quiz;

	Quiz.NumberOfQuestion = ReadHowManyQuestionsNumber();
	Quiz.QuestionLevel = ReadQuestionLevel();
	Quiz.OperationType = ReadOperationType();

	GenerateQuizQuestions(Quiz);
	AskAndCorrectQuestonListAnswer(Quiz);
	PritTheFinalQuiz(Quiz);
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void StartGame()
{
	char PlayAgain = 'Y';

	do
	{
		ResetScreen();
		PlayMathGame();

		cout << "\nDo You Want To Play Again ? Y/N" << endl;
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');

}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}