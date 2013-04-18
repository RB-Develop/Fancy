class Scene
{
public:
	Scene();
	~Scene(void);

	enum State{
		LOADING,
		PLAYING,
		PAUSED,
		EXITING
	};

	State state;
};

