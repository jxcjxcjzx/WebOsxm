class Section {

  float start;
  float duration;

  /**
   * Creates a section
   * @param start the start of the section
   * @param duration the duration of the section
   */
  public Section(float start, float duration) {
    this.start = start;
    this.duration = duration;
  }

  /**
   * Gets the duration of a segment
   * @return the duration in seconds
   */
  public float getDuration() {
    return duration;
  }

  /**
   * Gets the start time of a section
   * @return the start time (in seconds)
   */
  public float getStart() {
    return start;
  }

  public String toString() {
    return "  Start: " + start + "  Dur: " + duration;
  }
}


