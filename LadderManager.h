#pragma once
#define MAX_GAME_TIME 60480
#define PORT_START 5690


class LadderManager
{
public:
    LadderManager(int InCoordinatorArgc, char** inCoordinatorArgv);
    bool LoadSetup();
	void RunLadderManager();

private:
	bool SaveReplay(sc2::Connection *client, const std::string & path);
	bool ProcessObservationResponse(SC2APIProtocol::ResponseObservation Response, std::vector<sc2::PlayerResult>* PlayerResults);
	std::string GetBotCommandLine(BotConfig Config, int GamePort, int StartPort);
	sc2::GameRequestPtr CreateLeaveGameRequest();
	sc2::GameRequestPtr CreateQuitRequest();
	ResultType GetPlayerResults(sc2::Connection * client);
	ResultType StartGame(BotConfig Agent1, BotConfig Agent2, std::string Map);
    void StartCoordinator();
    void LoadAgents();
    void GetMapList();
    void UploadMime(ResultType result, Matchup ThisMatch);
    std::map<std::string, BotConfig> BotConfigs;
    std::vector<std::string> MapList;

	void SaveError(std::string Agent1, std::string Agent2, std::string Map);

    int CoordinatorArgc;
    char **CoordinatorArgv;

    int32_t MaxGameTime;
    bool Sc2Launched;
    sc2::Coordinator *coordinator;
    LadderConfig *Config;
};

LadderManager *LadderMan;
