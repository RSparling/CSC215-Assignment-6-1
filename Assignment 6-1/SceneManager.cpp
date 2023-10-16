#include "SceneManager.h"

/*
notes for scene bilding
resource codes:
m - money
f - food
e - energy
s - special, will always succeed and add to player stats
*/
//Builds initial scenes
SceneManager::SceneManager()
{
	/*
	this could realistically be removed from here to a seperate class that builds the scenes from a json file,
	though it is done through the builder pattern due to time constraints.
	*/

	LandLordScene = Scene(
		"We made it dave!Now to pay the landlord the money!"
	)
		.AddOption(Option(
			"Pay the Landlord rent.",
			"Wow Dave, we made it! And luckily we made some extra cash along the way or you wouldn't have been able to pay\n"
			"your share of the rent. Good job, now we can do this next month where you'll hopefully mess up less.\n",
			"Dave, is that wallet empty? I can't beleive you dont have the money for rent. You had one job Dave, one job. I am\n"
			"extremely dissapointed in you. Let's go back to the flat and start packing so we're ready when the eviction ferret\n"
			"shows up.",
			'm', 6, 0, 0, 0
		))
		.AddOption(Option(
			"Fight the Landlord",
			"Dave, put him down dave. No, dont do that! Put down the street sign! Oh wow, you actually won. I'm surprised."
			"Good job Dave, now we never have to pay rent again!\n",
			"Dave, what are you-! No, Dave! You fool, you shouldn't be fighting barehanded! Maybe if you got that knife from\n"
			"the squirrel you would have had a chance! Well, I guess it's time to find a new schmuck to pay for rent.",
			'e', 6, 0, 0, 0
		))
		.AddOption(Option(
			"Offer the LandLord snacks",
			"Wow Dave, you manage to have him defer rent untill next month by bribing him with food. I didnt expect that to\n"
			"work but here we are. Huh.",
			"Dave, why would he defer rent just because you offered him a twinkie, an old mint and some used gum? Now he's\n"
			"going to evict us because you decided to keep messing around. Great job.",
			'f', 6, 0, 0, 0
		)
		);

	LoseScene = *new Scene(
		"Dave, what's wrong? Oh no dave, you ruined everything! You really are useless, arent you?"
	);

	IntroductoryScene = *new Scene(
		"In a world of crazed animals and utter absurdity you live with dead beat room mates who refuse to help pay rent.\n"
		"While Chris and Mike bumb around it looks like it's up to you, Dave, to track down our landlord and give him our\n"
		"rent payment. I have faith in you Dave. Press any key to continue your adventure.\n\n"
		"What's that, where's my part of the rent? I'm sorry, I'm a bit short. Here, how about I narrorate your entire   \n"
		"adventure and tell you how to play. Press 'w' and 's' to navigate options and 'e' to confirm. Now confirm so we \ncan get going.");

	//squirrel scene
	SceneDictionary.push_back(Scene(
		"Oh my god Dave, it's a squrrel. Whoah, I think he wants your wallet. Be careful dave he has a knife and I think he's \n"
		"smoking! I dont even know how a squirrel can smoke dave, that cannot be healthy. What are you gonna do dave? I would \n"
		"just run but that's just me.")
		.AddOption(
			Option(
				//Text
				"Give the squirrel a dollar.",
				//success
				"Dave, what are you doing? We need that money for rent! Damn it dave, I cant believe you just gave away some of our\n"
				"rent money. You worked so hard for that and now it's gone. Boo you dave, boo you. When you're done being ashamed of \n"
				"yourself hit any key so we can get going.\n",
				//fail
				"Dave, is that wallet empty? I cant believe you were gonna try to pay him to go away but what's even worse is that\n"
				"you were about to try to pay him to leav with money you didn't even have. Shame on you dave, thanks to you bungling\n"
				"all of your own hard work we're all going to be out of a place to live.",
				//results
				'm', 1, -1, 0, 0)
		)

		.AddOption(
			Option(
				//Text
				"Give the squirrel a snickers.",
				//Success
				"Good thinking Dave, that squirrel I didn't realize that the squirrel was just hangry. I guess it's just like they say,\n"
				"you're not you when your hungry. Now let's get goind dave before the squirrel realizes that he can still try to take \n"
				"your wallet.\n",
				//fail
				"Dave what are you digging around in your pocket for, you got rid of your last candy bar a while ago. Oh no, it's to\n"
				"late now, the squirrel has you at knife point, oh the humanity! Quick dave, throw a couple dollars at it! Hit any \n"
				"key when your ready to run, quick!",
				//reults
				'f', 1, 0, -1, 0)
		)
		.AddOption(
			Option(
				//Text
				"Bro down with the squirrel.",
				//Success
				"Good thinking Dave, that squirrel I didn't realize that the squirrel was just hangry. I guess it's just like they say,\n"
				"you're not you when your hungry. Now let's get goind dave before the squirrel realizes that he can still try to take \n"
				"your wallet.\n",
				//Fail
				"Dave what are you digging around in your pocket for, you got rid of your last candy bar a while ago. Oh no, it's to\n"
				"late now, the squirrel has you at knife point, oh the humanity! Quick dave, throw a couple dollars at it! Hit any \n"
				"key when your ready to run, quick!",
				//reults
				'e', 1, 1, 0, 0)
		)
	);

	//Dog Encounter
	SceneDictionary.push_back(
		Scene(
			"Look, it's a dog! How adorable. You should take a moment to admire it dave, I think the landlord can wait. I wonder \n"
			"who's dog this is or if they have an owner at all. For all we know Dave he could be a stray. I think it might have\n"
			"something in it's mouth.\n\n")
		.AddOption(Option( //Pet Dog
			//Text
			"Pet the Dog.",
			//Success
			"Oh, that's pretty nice of you Dave, I didn't expect you to be such a dog person. I honestly though you were kind\n"
			"of a jerk, especially with the constantly complaining about us not paying rent. Then again I guess only a real\n"
			"monster could hate dogs. Okay, let's get going before I get fleas or something. Come on, stop petting it and hit \n"
			"any button!\n",
			//"Good thinking checking the collar Dave. I didn't peg you as the common sense type, probably because of you still having \n"
			"Oh, that's pretty nice of you Dave, I didn't expect you to be such a dog person. I honestly though you were kind\n"
			"of a jerk, especially with the constantly complaining about us not paying rent. Then again I guess only a real\n"
			"monster could hate dogs. Okay, let's get going before I get fleas or something. Come on, stop petting it and hit \n"
			"any button!\n",
			's', 0, 0, 0, 1
		))
		.AddOption(Option( //Check Collar
			"Check the collar.",

			"Good thinking checking the collar Dave. I didn't peg you as the common sense type, probably because of you still having \n"
			"us as flat mates. What does it say, 'Margo'? Kind of a weird name for a dog. Oh no, it's taking off. I guess we'll never\n"
			"know who it belongs to. Oh well, hit any button so we can get going.\n\n",

			"Good thinking checking the collar Dave. I didn't peg you as the common sense type, probably because of you still having \n"
			"us as flat mates. What does it say, 'Margo'? Kind of a weird name for a dog. Oh no, it's taking off. I guess we'll never\n"
			"know who it belongs to. Oh well, hit any button so we can get going.\n\n",

			's', 0, 0, 0, 0
		))
		.AddOption(Option( //Feed the Dog
			"Feed the dog.",
			//success
			"Good thinking Dave, if it's a stray it probably hasn't eaten in a while. You're doing good work dave.  Maybe there's a heart\n"
			"inside of that that black hole of a heart. Somewhere. Maybe not. Oh hey, it dropped dollar! We could use that. When you're\n"
			"a button already so we can get goin!\n\n",

			"Oh no dave, you dont have anything to eat. That's too bad, you got it's hopes up to and now it's gonna be sad. You \n"
			"monster. If you're done making an innocent mutt feel bad then hit a button so we can go.\n",

			'f', 1, 0, 0, 0
		))
	);

	SceneDictionary.push_back(
		Scene(
			"Oh look an owl. Dave, you should see if it has a riddle.As everyone know owls love riddles.What, you didnt \n"
			"know this? Well dave it's probably not the first or the last thing that you didnt know. Now let's get over there \n"
			"so we can do some riddle solving Okay, what is a house hold item that's always on the move yet never leaves its \n"
			"spot? Wow, that's a hard one.\n"
		)
		.AddOption(
			Option(
				"Clock",

				"Oh no dave, you got it wrong!Now you need to give him a treat.Wait, you didn't know how that works? Dave, if you\n"
				"had to fill a book with everything you didnt know then you probably could fill a library. Anyways, hit a button so\n"
				"we can go.",

				"Oh no dave, you got it wrong! Now you need to give him a treat. Wait, you didn't know how that works? Dave, if you\n"
				"had to fill a book with everything you didnt know then you probably could fill a library. Oh and you dont have any?\n"
				"I'll spot you this once, now hit a button so we can go.",

				's', 0, 0, 1, 0
			)
		)
		.AddOption(
			Option(
				"Refrigerator",

				"Wow dave, i can't beleive you're right. Now he has to give us a dollar, as is the owl code. Now hit a button. take the dollar\n"
				"and let's get going.\n",

				"Wow dave, i can't beleive you're right. Now he has to give us a dollar, as is the owl code. Now hit a button. take the dollar\n"
				"and let's get going.\n",

				's', 1, 1, 0, 0
			)
		)
		.AddOption(
			Option(
				"Chair",

				"Damn, that's what I thought to! You know, because of the legs. Anyways, now you need to give him a treat. Wait, you didn't \n"
				"know how that works? Dave, if you had to fill a book with everything you didnt know then you probably could fill a library.\n"
				"Anyways, hit a button so we can go.",

				"Damn, that's what I thought to! You know, because of the legs. Anyways, now you need to give him a treat. Wait, you didn't \n"
				"know how that works? Dave, if you had to fill a book with everything you didnt know then you probably could fill a library.\n"
				"Anyways, hit a button so we can go.",

				's', 0, -1, 0, 0
			)
		)
	);

	SceneDictionary.push_back(
		Scene(
			"Oh look, a shrew dave! He seems to be rather shrewd. Maybe he'll have something of use. You should do something Dave!"
		).AddOption(Option(
			"Ask it advice about money",
			"It took alot of work but you managed to learn about investment portfolios which miraculously turned into more money!",
			"You try to ask him about money but he says that you're too poor to understand",
			'm', 4, -8, 0, 0
		)
		)
		.AddOption(Option(
			"Ignore it",
			"Good Idea Dave, by ignoring it it cant do anything to us!",
			"Good Idea Dave, by ignoring it it cant do anything to us!",
			's', 0, 0, 0, 0
		)
		)
		.AddOption(Option(
			"Steal his Wallet",
			"Dave you monster, what are you doint to him!? Well, at least now we got some mroe money to pay rent."
			"\nPress a button so we can get going.",
			"Wow Dave, I cant believe you got beat up by a shrew. When you're done crying press a button so we can go.",
			'e', 4, 3, 0, 0
		)
		));

	SceneDictionary.push_back(
		Scene(
			"Dave, oh no! It's a raccoon bandit, wearing a mask and brandishing a tiny but menacing looking twig like a weapon. He wants to rob you!"
		).AddOption(Option(
			"Offer Him Some Food",
			"Well done, Dave. Your quick thinking paid off, and you've still got your supplies.",
			"Unfortunately, Dave, your offering wasn't enough to satisfy the bandit's appetite and he took some of your cash of Dac Monalds.",
			'f', 2, 3, 2, 0
		)
		)
		.AddOption(Option(
			"Run",
			"You somehow manage to outrun a raccoon. Impressive, Dave! You get to keep your stuff and your energy. What a feat!",
			"Oh no, Dave, not fast enough! The raccoon bandit catches up and snatches your wallet. Bravo, what a fail!",
			'e', 1, 2, 0, 0
		)
		));

	SceneDictionary.push_back(
		Scene(
			"Dave, brace yourself for another riveting city encounter! This time, it's a slick-looking seagull in a pinstripe suit and \nsunglasses, strutting your way. He's got a sly grin that could rival a fox. "
		)
		.AddOption(
			Option(
				"Engage in a Card Game",
				"Well, would you look at that! Dave, you're a card shark in disguise. You won the game, and the seagull hands over some of \nhis ill-gotten gains. A true high roller, you are! ",
				"Oh dear, Dave, your poker face is no match for the seagull's cunning. He just cleaned you out and leaves you in financial ruin.\n Bravo on the gamble!",
				'm', 3, -4, 0, 0
			)
		)
		.AddOption(
			Option(
				"Attempt to Bargain",
				"Remarkable, Dave! Your smooth talking convinced the seagull to lower his demands. Now he only robbed you a little bit!",
				"Wow dave, you're really bad at negotiating. You're lucky he didnt take your kidney.",
				'f', 1, 2, 2, 2
			)
		)
	);
}

//get the main text for the scene
string SceneManager::GetSceneText()
{
	string _text = currentScene.GetText();
	return _text;
}

//get text for specific option
string SceneManager::GetTextAtOption(int index) {
	vector<Option> _options;
	_options = currentScene.GetOptions();
	string _text = _options[index].GetOptionText();
	return _text;
}

//returns text for all option choices.
vector<string> SceneManager::GetAllOptionText()
{
	vector<string> _options;
	vector<Option> _sceneOptions = currentScene.GetOptions();

	for (Option o : _sceneOptions) {
		_options.push_back(o.GetOptionText());
	}

	return _options;
}

//set current scene to intro scene
void SceneManager::OverrideSceneToIntroduction()
{
	currentScene = IntroductoryScene;
}

//set current scene to end scene
void SceneManager::OverrideSceneToEnding()
{
	currentScene = LoseScene;
}

void SceneManager::OverrideSceneToLandLord()
{
	currentScene = LandLordScene;
}

//shuffles the scenes and builds the adventure.
void SceneManager::BuildAdventure(int legnth)
{
	int remainingScenesToAdd = legnth;

	auto rng = std::default_random_engine{};// Gets random numbers;
	for (; remainingScenesToAdd > 0; remainingScenesToAdd--) {
		std::shuffle(std::begin(SceneDictionary), std::end(SceneDictionary), rng);
		SceneQueue.push_back(SceneDictionary[0]);
	}
}

//proceed to the next scene, if its the end go to the end scene
void SceneManager::Advance()
{
	if (isLastScene)
		return;
	sceneIndex += 1;
	if (sceneIndex == SceneQueue.size() - 1)
	{
		currentScene = LoseScene;
		isLastScene = true;
		return;
	}
	currentScene = SceneQueue[sceneIndex];
}

bool SceneManager::IsLastScene() {
	return isLastScene;
}

//only checks if the player passes
bool SceneManager::CheckPlayerSuccess(int index, int money, int food, int energy)
{
	Option option = currentScene.GetOption(index);
	char reqResource = option.GetRequiredResource();
	int reqAmmount = option.GetRequiredAmmount();

	switch (reqResource) {
	case 'f':
		if (food - reqAmmount > 0)
			return true;
		return false;
	case 'm':
		if (money - reqAmmount > 0)
			return true;
		return false;
	case 'e':
		if (energy - reqAmmount > 0)
			return true;
		return false;
	case 's':
		return true;
	default:
		system("cls");
		printf("An error had occured, unexpeded required resource of code: " + reqResource);
		return true;
	}
}

vector<int> SceneManager::GetConsequences(int index)
{
	return currentScene.GetOption(index).GetConsequences();
}

bool SceneManager::IsOptionSpecial(int index)
{
	Option _option = currentScene.GetOption(index);
	if (_option.IsSpecial())
		return true;
	return false;
}

char SceneManager::GetResourceType(int index) {
	Option _option = currentScene.GetOption(index);
	return _option.GetRequiredResource();
}

int SceneManager::GetResourceAmmont(int index) {
	Option _option = currentScene.GetOption(index);
	return _option.GetRequiredAmmount();
}

string SceneManager::GetResultText(int index, bool success)
{
	Option _option = currentScene.GetOption(index);
	if (success)
		return _option.GetSuccessText();

	return _option.GetFailText();
}