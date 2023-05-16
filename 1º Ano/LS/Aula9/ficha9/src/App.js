import { useState } from "react";
import "./assets/styles/App.css";
import { ControlPanel, Footer, Header, GamePanel } from "./components";

function App() {
  const [gameStarted, setGameStarted] = useState(false);
  const [selectedLevel, setSelectedLevel] = useState("0");

  const handleGameStart = () => (gameStarted === true ? setGameStarted(false) : setGameStarted(true));

  const handleLevelChange = (level) => setSelectedLevel(level);

  return (
    <div id="container">
      <Header />
      <div className="main-content">
        <ControlPanel 
          gameStarted={gameStarted}
          onGameStart={handleGameStart}
          selectedLevel={selectedLevel}
          onLevelChange={handleLevelChange}
        />
        <GamePanel />
      </div>
      <Footer />
    </div>
  );
}

export default App;
