#ifndef INDEX_H
#define INDEX_H
const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8" />
    <link rel="icon" type="image/svg+xml" href="/vite.svg" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <meta
      name="description"
      content="ClusterDuck Network Portal by the ClusterDuck Protocol"
    />
    <title>Tea Houses</title>
    <style>
      body {
        font-family: Arial, sans-serif;
        display: flex;
        justify-content: center;
        align-items: center;
        min-height: 100vh;
        margin: 0;
        background-color: #f0f0f0;
        padding: 20px;
        box-sizing: border-box;
      }
      .form-container {
        background-color: white;
        border: 2px solid #ffa500;
        border-radius: 10px;
        padding: 20px;
        width: 100%;
        max-width: 300px;
        box-sizing: border-box;
      }
      h1,
      h2,
      label {
        color: #ffa500;
      }
      input[type="text"] {
        width: 100%;
        padding: 5px;
        margin-bottom: 10px;
        border: 1px solid #ffa500;
        border-radius: 5px;
      }
      .quantity-control {
        display: flex;
        align-items: center;
        justify-content: space-between;
        margin-bottom: 10px;
        flex-wrap: wrap;
      }
      .quantity-control label {
        flex: 1 1 60%;
        margin-bottom: 5px;
      }
      .quantity-control div {
        flex: 1 1 40%;
        display: flex;
        justify-content: flex-end;
        align-items: center;
      }
      .quantity-control button {
        background-color: white;
        border: 1px solid #ffa500;
        color: #ffa500;
        border-radius: 50%;
        width: 25px;
        height: 25px;
        cursor: pointer;
        font-size: 16px;
      }
      .quantity-control span {
        margin: 0 10px;
      }
      @media (max-width: 320px) {
        .form-container {
          padding: 10px;
        }
        h1 {
          font-size: 1.5em;
        }
        h2 {
          font-size: 1.2em;
        }
      }
    </style>
  </head>

  <body>
    <div id="app">
      <div class="form-container">
        <h1>TeaHouse Order Form</h1>
        <form id="orderForm">
          <input
            type="text"
            id="teahouse"
            placeholder="Name of TeaHouse"
            required
          />
          <input
            type="text"
            id="person"
            placeholder="Name of Person"
            required
          />

          <h2>Food</h2>
          <div id="foodItems">
            <div class="quantity-control">
              <label for="meat">Meat</label>
              <div>
                <button type="button" onclick="updateQuantity('meat', -1)">
                  -
                </button>
                <span id="meatQuantity">1</span>
                <button type="button" onclick="updateQuantity('meat', 1)">
                  +
                </button>
              </div>
            </div>
            <div class="quantity-control">
              <label for="chicken">Chicken</label>
              <div>
                <button type="button" onclick="updateQuantity('chicken', -1)">
                  -
                </button>
                <span id="chickenQuantity">1</span>
                <button type="button" onclick="updateQuantity('chicken', 1)">
                  +
                </button>
              </div>
            </div>
            <div class="quantity-control">
              <label for="buff">Buff</label>
              <div>
                <button type="button" onclick="updateQuantity('buff', -1)">
                  -
                </button>
                <span id="buffQuantity">1</span>
                <button type="button" onclick="updateQuantity('buff', 1)">
                  +
                </button>
              </div>
            </div>
            <div class="quantity-control">
              <label for="pork">Pork</label>
              <div>
                <button type="button" onclick="updateQuantity('pork', -1)">
                  -
                </button>
                <span id="porkQuantity">1</span>
                <button type="button" onclick="updateQuantity('pork', 1)">
                  +
                </button>
              </div>
            </div>
            <div class="quantity-control">
              <label for="vegetables">Vegetables</label>
              <div>
                <button
                  type="button"
                  onclick="updateQuantity('vegetables', -1)"
                >
                  -
                </button>
                <span id="vegetablesQuantity">1</span>
                <button type="button" onclick="updateQuantity('vegetables', 1)">
                  +
                </button>
              </div>
            </div>
            <div class="quantity-control">
              <label for="bread">Bread</label>
              <div>
                <button type="button" onclick="updateQuantity('bread', -1)">
                  -
                </button>
                <span id="breadQuantity">1</span>
                <button type="button" onclick="updateQuantity('bread', 1)">
                  +
                </button>
              </div>
            </div>
            <div class="quantity-control">
              <label for="rice">Rice</label>
              <div>
                <button type="button" onclick="updateQuantity('rice', -1)">
                  -
                </button>
                <span id="riceQuantity">1</span>
                <button type="button" onclick="updateQuantity('rice', 1)">
                  +
                </button>
              </div>
            </div>
          </div>

          <h2>Drinks</h2>
          <div>
            <input type="checkbox" id="tea" name="tea" />
            <label for="tea">Tea</label><br />
            <input type="checkbox" id="softDrinks" name="softDrinks" />
            <label for="softDrinks">Soft Drinks</label><br />
            <input type="checkbox" id="hardDrinks" name="hardDrinks" />
            <label for="hardDrinks">Hard Drinks</label>
          </div>

          <h2>General Medicine</h2>
          <div>
            <input type="checkbox" id="paracetamol" name="paracetamol" />
            <label for="paracetamol">Paracetamol</label><br />
            <input type="checkbox" id="dimox" name="dimox" />
            <label for="dimox">Dimox</label><br />
            <input type="checkbox" id="oxygenCans" name="oxygenCans" />
            <label for="oxygenCans">Oxygen Cans</label>
          </div>

          <h2>Other:</h2>
          <textarea type="text" id="other" placeholder="Other items"></textarea>
          <button type="submit" class="submit-button">Submit Order</button>
        </form>
        <div id="orderSummary"></div>
      </div>
    </div>

    <!-- Run javascript actions here -->
    <script type="text/javascript">
      const MUID_URL = "/muidStatus.json";
      const MUID_PARAM_NAME = "muid";
      const CLIENT_ID_LENGTH = 4;
      const CLIENT_ID_KEY = "CLIENT_ID";
      const NOT_ACKED_MSG =
        "The message may have been received, but we're still waiting for confirmation.";
      var messageController;
      var muidRequest;

      function updateQuantity(item, change) {
        const quantityElement = document.getElementById(`${item}Quantity`);
        let quantity = parseInt(quantityElement.textContent);
        quantity = Math.max(0, quantity + change);
        quantityElement.textContent = quantity;
      }

      function CreateMuidRequest(muid) {
        return MuidRequest(
          muid,
          document.getElementById("muidStatus"),
          document.getElementById("muidStatusMessage")
        );
      }

      var MessageController = function () {
        var loadListener = function () {
          // this.responseText should be something like: {"muid":"ABCD"}
          var res = JSON.parse(this.responseText);
          messageController.saveLastMuid(res.muid);
          var errEl = document.getElementById("makeshiftErrorOutput");
          if (!errEl.classList.toString().includes("hidden")) {
            errEl.innerHTML = "";
            errEl.classList.add("hidden");
          }
        };
        var errorListener = function () {
          var errorMessage =
            "There was an error sending the message. Please try again.";
          console.log(errorMessage);
          var errEl = document.getElementById("makeshiftErrorOutput");
          errEl.innerHTML = errorMessage;
          errEl.classList.remove("hidden");
        };
        var showSentMessage = function (commentsInput) {
          var lastMessageField = document.getElementById("lastMessageField");
          lastMessageField.innerHTML = commentsInput.value;
          // TODO: Create a new DOM view so multiple messages can be shown
          var msgSection = document.getElementById("lastMessageSection");
          msgSection.classList.remove("hidden");
        };
        return {
          sendMessage: function () {},
          saveLastMuid: function (muid) {
            <!-- for checking if message was acked on duk, needs fixed -->
            document.getElementById("lastMessageMuid").innerHTML = muid;
            muidRequest = CreateMuidRequest(muid);
            muidRequest.requestMuidStatus();
          },
        };
      };
      var MuidRequest = function (muid, statusEl, messageEl) {
        var showStatus = function (status, message) {
          statusEl.innerHTML = status;
          messageEl.innerHTML = message;
        };
        var loadListener = function () {
          var res = JSON.parse(this.responseText);
          showStatus(res.status, res.message);
          if (res.status === "not_acked") {
            showStatus("not_acked", NOT_ACKED_MSG);
            setTimeout(requestMuidStatus, 1000);
          }
        };
        var errorListener = function () {
          showStatus("error", "There was an unknown error");
          setTimeout(requestMuidStatus, 1000);
        };
        var requestMuidStatus = function () {
          var req = new XMLHttpRequest();
          req.addEventListener("load", loadListener);
          req.addEventListener("error", errorListener);
          var url = MUID_URL;
          var params = new URLSearchParams("");
          params.append(MUID_PARAM_NAME, muid);
          url += "?" + params.toString();
          req.open("GET", makeUrlUnique(url));
          req.send();
        };
        return {
          requestMuidStatus: requestMuidStatus,
        };
      };

      function makeUrlUnique(url) {
        // Makes the URL bypass the browser's cache.
        // https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest/Using_XMLHttpRequest#bypassing_the_cache
        return url + (/\?/.test(url) ? "&" : "?") + new Date().getTime();
      }

      function storageAvailable(type) {
        var storage;
        try {
          storage = window[type];
          var x = "__storage_test__";
          storage.setItem(x, x);
          storage.removeItem(x);
          return true;
        } catch (e) {
          return (
            e instanceof DOMException &&
            // everything except Firefox
            (e.code === 22 ||
              // Firefox
              e.code === 1014 ||
              // test name field too, because code might not be present
              // everything except Firefox
              e.name === "QuotaExceededError" ||
              // Firefox
              e.name === "NS_ERROR_DOM_QUOTA_REACHED") &&
            // acknowledge QuotaExceededError only if there's something already stored
            storage &&
            storage.length !== 0
          );
        }
      }

      function generateClientId() {
        var result = "";
        var characters = "ABCDEFGHIJKLMNPQRSTUVWXYZ123456789";
        for (var i = 0; i < CLIENT_ID_LENGTH; i++) {
          var randomIndex = Math.floor(Math.random() * characters.length);
          result += characters.charAt(randomIndex);
        }
        return result;
      }

      function initialize() {
        var clientId;
        if (storageAvailable("localStorage")) {
          if (window.localStorage.getItem(CLIENT_ID_KEY)) {
            clientId = window.localStorage.getItem(CLIENT_ID_KEY);
          } else {
            clientId = generateClientId();
            window.localStorage.setItem(CLIENT_ID_KEY, clientId);
          }
          document.getElementById("clientId").value = clientId;
        } else {
          document.getElementById("clientId").value = "";
        }
        messageController = MessageController();
      }

      document
        .getElementById("orderForm")
        .addEventListener("submit", async function (e) {
          const form = {
            teahouseName: "",
            personName: "",
            foodItems: {
              meat: 0,
              chicken: 0,
              buff: 0,
              pork: 0,
              vegetables: 0,
              bread: 0,
              rice: 0,
            },
            drinks: [],
            medicines: [],
            other: "",
          };

          e.preventDefault();

          const teahouse = document.getElementById("teahouse").value;
          const person = document.getElementById("person").value;
          const other = document.getElementById("other").value;

          let orderSummary = `<h2>Order Summary</h2>`;
          orderSummary += `<p><strong>TeaHouse:</strong> ${teahouse}</p>`;
          orderSummary += `<p><strong>Person:</strong> ${person}</p>`;
          orderSummary += `<h3>Food Items:</h3>`;

          const foodItems = [
            "meat",
            "chicken",
            "buff",
            "pork",
            "vegetables",
            "bread",
            "rice",
          ];
          foodItems.forEach((item) => {
            const quantity = document.getElementById(
              `${item}Quantity`
            ).textContent;
            if (parseInt(quantity) > 0) {
              form.foodItems[`${item}`] = quantity;
              orderSummary += `<p>${item}: ${quantity}</p>`;
            }
          });

          const drinks = [];
          const medicines = [];

          // Select all the checkboxes in each section by name prefix
          const drinkCheckboxes = document.querySelectorAll(
            'input[name="tea"], input[name="softDrinks"], input[name="hardDrinks"]'
          );
          const medicineCheckboxes = document.querySelectorAll(
            'input[name="paracetamol"], input[name="dimox"], input[name="oxygenCans"]'
          );

          // Collect selected drinks
          drinkCheckboxes.forEach((checkbox) => {
            if (checkbox.checked) drinks.push(checkbox.name);
          });

          // Collect selected medicines
          medicineCheckboxes.forEach((checkbox) => {
            if (checkbox.checked) medicines.push(checkbox.name);
          });

          let resultText = "";

          if (drinks.length)
            resultText += `Selected Drinks: ${drinks.join(", ")}\n`;
          if (medicines.length)
            resultText += `Selected Medicines: ${medicines.join(", ")}`;

          if (!resultText) resultText = "No items selected.";

          orderSummary += resultText;

          // other
          if (other) {
            orderSummary += `<h3>Other Items:</h3>`;
            orderSummary += `<p>${other}</p>`;
          }

          const summaryElement = document.getElementById("orderSummary");
          summaryElement.innerHTML = orderSummary;
          summaryElement.style.display = "block";

          form.teahouseName = teahouse;
          form.personName = person;
          form.other = other;
          form.drinks = drinks;
          form.medicines = medicines;
          const queryParams = new URLSearchParams(form).toString();

          const getPairs = (obj, keys = []) =>
            Object.entries(obj).reduce((pairs, [key, value]) => {
              if (typeof value === "object")
                pairs.push(...getPairs(value, [...keys, key]));
              else pairs.push([[...keys, key], value]);
              return pairs;
            }, []);

          const x = getPairs(form)
            .map(
              ([[key0, ...keysRest], value]) =>
                `${key0}${keysRest.map((a) => `[${a}]`).join("")}=${value}`
            )
            .join("&");

          const send = async () => {
            await fetch(`formSubmit.json?${x}`, {
              method: "GET",
            });
          };

          await send();
        });

      // initialize();
    </script>
  </body>
</html>
)=====";
#endif