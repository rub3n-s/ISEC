import React from "react";
import "./card.css";
import { PLACEHOLDER_CARDBACK_PATH, PLACEHOLDER_CARD_PATH } from "../../constants";

const Card = ({name}) => {
  return (
    <div className="card flipped" data-logo={name}>
      <img src={PLACEHOLDER_CARDBACK_PATH} className="card-back" alt="card placeholder" />
      <img src={`${PLACEHOLDER_CARD_PATH}${name}.png`} className="card-front" alt="card" />
    </div>
  );
};

export default Card;
