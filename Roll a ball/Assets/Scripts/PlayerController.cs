using UnityEngine;
using System.Collections;
using UnityEngine.UI;


public class PlayerController : MonoBehaviour {

	public Text countText;
	public Text winText;

	private Rigidbody rb;
	private int count;
	public float speed;


	// Use this for initialization
	void Start () {
		count = 0;
		setCountText ();
		winText.text = "";
		rb = GetComponent<Rigidbody> ();
	}

	void FixedUpdate()
	{
		// This is for moving a ball
		float moveHorizontal = Input.GetAxis("Horizontal");
		float moveVertical = Input.GetAxis("Vertical");
		Vector3 movement = new Vector3 (moveHorizontal, 0, moveVertical);
		rb.AddForce (movement * speed);
	}

	void OnTriggerEnter (Collider other){
		if (other.gameObject.CompareTag ("Pick Up")) {
			other.gameObject.SetActive (false);
			count++;
			setCountText ();

		}
	}

	void setCountText(){
		countText.text = "Count: " + count.ToString ();
		if (count>=12)
			winText.text = "YOU WON!!!";
	}
}
