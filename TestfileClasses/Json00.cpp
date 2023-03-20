#include "Json00.h"

USING_NS_CC;

Scene* Json00::createScene()
{
	return Json00::create();
}

bool Json00::init()
{
	if (!Scene::init())
	{
		return false;
	}
	///////////////////
	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	FileUtils* util = FileUtils::getInstance();

	// read json from file
	std::string path = util->fullPathForFilename("data/test_data.json");
	std::string jsonData = util->getStringFromFile(path);
	log("%s\n", jsonData.c_str());

	rapidjson::Document doc;
	doc.Parse(jsonData.c_str());
	if (doc.HasParseError())
	{
		log("GetParseError %s \n", doc.GetParseError());
		return false;
	}

	std::string str = doc["string"].GetString();
	log("name = %s", str.c_str());

	//뒤에 있는 항목을 먼저 읽었다.
	int n1 = doc["integer"].GetInt();
	doc["integer"].SetInt(100);
	log("i=%d", n1);

	bool isTF = doc["bool"].GetBool();
	log("t=%d", isTF);

	float n2 = doc["float"].GetFloat();
	log("f= %.2f", n2);

	const rapidjson::Value&arr = doc["array"];
	if (arr.IsArray())
	{
		for (rapidjson::SizeType i = 0; i < arr.Size(); ++i)
		{
			auto name = arr[i]["name"].GetString();
			auto age = arr[i]["age"].GetInt();
			log("name:%s, age:%d", name, age);
		}
	}

	return true;
}
